# -*- coding: utf-8 -*-
"""把 lesson01~lesson11 的所有 .c 文件整合成一份带语法高亮的 Word 复习手册。"""
import os
import re
from datetime import datetime

from docx import Document
from docx.shared import Pt, Cm, RGBColor
from docx.enum.text import WD_ALIGN_PARAGRAPH, WD_LINE_SPACING, WD_BREAK
from docx.enum.table import WD_TABLE_ALIGNMENT
from docx.oxml.ns import qn
from docx.oxml import OxmlElement

ROOT = "/Users/vivian/c 语言"
OUT = os.path.join(ROOT, "C语言复习手册-lesson01至lesson11.docx")

KEYWORDS = {
    "auto","break","case","char","const","continue","default","do","double","else","enum",
    "extern","float","for","goto","if","inline","int","long","register","restrict","return",
    "short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void",
    "volatile","while","_Bool","_Complex","_Imaginary",
}
TYPES = {"FILE","size_t","bool","true","false","NULL","EOF","printf","scanf","malloc","free"}

C_KW   = RGBColor(0x1F, 0x4E, 0x9C)   # 关键字 蓝
C_PRE  = RGBColor(0x7B, 0x1F, 0xA2)   # 预处理 紫
C_CMT  = RGBColor(0x2E, 0x7D, 0x32)   # 注释   绿
C_STR  = RGBColor(0xA3, 0x15, 0x15)   # 字符串 红
C_NUM  = RGBColor(0xB4, 0x53, 0x09)   # 数字   橙
C_TXT  = RGBColor(0x1A, 0x1A, 0x1A)   # 正文   近黑
C_ACC  = "1F4E9C"
C_SUB  = RGBColor(0x5A, 0x6B, 0x7B)

TOKEN_RE = re.compile(
    r"(?P<comment>//[^\n]*|/\*.*?\*/)"
    r"|(?P<string>\"(?:\\.|[^\"\\])*\"|'(?:\\.|[^'\\])*')"
    r"|(?P<pre>^[ \t]*#[^\n]*)"
    r"|(?P<number>\b\d[\w.]*\b)"
    r"|(?P<word>[A-Za-z_]\w*)",
    re.S | re.M,
)


def natural_key(s):
    return [int(t) if t.isdigit() else t.lower() for t in re.split(r"(\d+)", s)]


def shade(p, hex_color):
    pPr = p._p.get_or_add_pPr()
    shd = OxmlElement("w:shd")
    shd.set(qn("w:val"), "clear")
    shd.set(qn("w:color"), "auto")
    shd.set(qn("w:fill"), hex_color)
    pPr.append(shd)


def left_border(p, color, size=8):
    pPr = p._p.get_or_add_pPr()
    bdr = pPr.find(qn("w:pBdr"))
    if bdr is None:
        bdr = OxmlElement("w:pBdr")
        pPr.append(bdr)
    left = OxmlElement("w:left")
    left.set(qn("w:val"), "single")
    left.set(qn("w:sz"), str(size))
    left.set(qn("w:space"), "0")
    left.set(qn("w:color"), color)
    bdr.append(left)


def set_run(run, ascii_font, ea_font, size, color=None, bold=False, italic=False):
    run.font.name = ascii_font
    run.font.size = Pt(size)
    run.font.bold = bold
    run.font.italic = italic
    if color is not None:
        run.font.color.rgb = color
    rPr = run._element.get_or_add_rPr()
    rf = rPr.find(qn("w:rFonts"))
    if rf is None:
        rf = OxmlElement("w:rFonts")
        rPr.append(rf)
    rf.set(qn("w:ascii"), ascii_font)
    rf.set(qn("w:hAnsi"), ascii_font)
    rf.set(qn("w:eastAsia"), ea_font)
    rf.set(qn("w:cs"), ascii_font)


def add_field(paragraph, instr):
    run = paragraph.add_run()
    fld = OxmlElement("w:fldChar"); fld.set(qn("w:fldCharType"), "begin")
    it = OxmlElement("w:instrText"); it.set(qn("xml:space"), "preserve"); it.text = instr
    fld2 = OxmlElement("w:fldChar"); fld2.set(qn("w:fldCharType"), "end")
    run._r.append(fld); run._r.append(it); run._r.append(fld2)
    return run


def tokenize(source):
    """产出 (text, color) 序列。"""
    out = []
    pos = 0
    for m in TOKEN_RE.finditer(source):
        if m.start() > pos:
            out.append((source[pos:m.start()], C_TXT))
        kind = m.lastgroup
        text = m.group()
        if kind == "comment":
            color = C_CMT
        elif kind == "string":
            color = C_STR
        elif kind == "pre":
            color = C_PRE
        elif kind == "number":
            color = C_NUM
        else:
            if text in KEYWORDS:
                color = C_KW
            elif text in TYPES:
                color = C_NUM
            else:
                color = C_TXT
        out.append((text, color))
        pos = m.end()
    if pos < len(source):
        out.append((source[pos:], C_TXT))
    return out


def add_code_block(doc, source, ctx):
    """按行写入代码，保持缩进与高亮。"""
    ctx["n"] += 1 if False else 0
    pieces = []
    for text, color in tokenize(source):
        lines = text.split("\n")
        for i, line in enumerate(lines):
            if i > 0:
                pieces.append(("__NL__", None))
            if line:
                pieces.append((line, color))
    cur = None
    for text, color in pieces:
        if text == "__NL__":
            cur = None
            continue
        if cur is None:
            cur = doc.add_paragraph()
            cur.paragraph_format.space_before = Pt(0)
            cur.paragraph_format.space_after = Pt(0)
            cur.paragraph_format.line_spacing_rule = WD_LINE_SPACING.EXACTLY
            cur.paragraph_format.line_spacing = Pt(11.5)
            cur.paragraph_format.left_indent = Cm(0.35)
            cur.paragraph_format.right_indent = Cm(0.15)
            shade(cur, "F6F8FA")
            left_border(cur, "9DB2CE", 8)
        r = cur.add_run(text)
        set_run(r, "Consolas", "微软雅黑", 8.5, color)
    # 结束间隔
    sp = doc.add_paragraph()
    sp.paragraph_format.space_before = Pt(2)
    sp.paragraph_format.space_after = Pt(8)
    sp.paragraph_format.line_spacing_rule = WD_LINE_SPACING.EXACTLY
    sp.paragraph_format.line_spacing = Pt(6)
    for r in sp.runs:
        r.font.size = Pt(4)


TOPIC_DICT = [
    ("hello", "HelloWorld 程序结构"), ("format", "格式化输出"), ("io_str", "字符串输入输出"),
    ("io_simple", "基本输入输出"), ("io", "输入输出"), ("string", "字符串"),
    ("convertion", "类型转换"), ("double_vs_float", "double 与 float 精度"),
    ("integer_constent", "整型常量"), ("compute_area", "面积计算"),
    ("operator_precedence", "运算符优先级"), ("eval_order", "求值顺序"),
    ("int-promoption", "整型提升"), ("arithmetic", "算术运算"), ("quotient", "整除与取余"),
    ("bits", "位运算"), ("inc_dec", "自增/自减"), ("comparison", "比较运算"),
    ("logical", "逻辑运算"), ("swap", "两数交换"), ("assign", "复合赋值"),
    ("parenthesis", "括号与优先级"), ("bool", "布尔类型"), ("expr", "表达式"),
    ("random", "随机数"), ("oneway-if", "单分支 if"), ("twoway-if", "双分支 if"),
    ("switch", "switch 多路分支"), ("max", "求最大值"), ("sort", "排序"),
    ("score", "成绩"), ("grade", "等级"), ("area", "面积"), ("learning", "学习时长累加"),
    ("loop", "循环"), ("while", "while 循环"), ("dowhile", "do-while 循环"),
    ("for", "for 循环"), ("nest", "循环嵌套"), ("matrix", "矩阵"), ("99-table", "九九乘法表"),
    ("count", "计数"), ("guess", "猜数字"), ("modi", "循环改动练习"),
    ("function", "函数"), ("syntax", "函数语法"), ("byref", "传址调用"),
    ("call", "函数调用"), ("parameter", "函数参数"), ("static", "static 静态变量"),
    ("prime", "素数判断"), ("facterial", "阶乘"), ("fibonacci", "斐波那契"),
    ("frog", "青蛙跳台阶（递归/DP）"), ("sum", "求和"), ("encipher", "加密"),
    ("input", "输入处理"), ("eof", "EOF 结束输入"), ("spec", "格式控制输入"),
    ("average", "平均值"), ("rain", "降雨量统计"), ("vecter", "向量"),
    ("array", "数组"), ("add", "相加"), ("char", "字符类型"), ("literal", "字面量"),
    ("strlen", "求字符串长度"), ("strcpy", "字符串复制"), ("strcat", "字符串拼接"),
    ("strcmp", "字符串比较"), ("strchr", "字符查找"), ("strstr", "子串查找"),
    ("fgets", "行输入 fgets"), ("toupper", "大小写转换"), ("tolower", "大小写转换"),
    ("pointer", "指针"), ("null", "空指针"), ("wild", "野指针"), ("index", "下标运算"),
    ("const", "const 限定"), ("void", "void 指针"), ("weekday", "星期推算"),
    ("rational", "有理数结构体"), ("struct", "结构体"), ("multi", "乘法"),
    ("gcd", "最大公约数"), ("basics", "基础"), ("definition", "定义"),
    ("ops", "运算"), ("self", "自身"), ("basic", "基础"), ("def", "定义"),
    ("回文数", "回文数判断"), ("整数反转", "整数反转"),
]


def guess_topics(filenames):
    hits = []
    seen = set()
    for fn in filenames:
        low = fn.lower()
        for key, val in TOPIC_DICT:
            if key.lower() in low and val not in seen:
                seen.add(val)
                hits.append(val)
    return hits[:4]


def build():
    lessons = sorted(
        [d for d in os.listdir(ROOT) if re.fullmatch(r"lesson\d{2}", d)],
        key=natural_key,
    )
    data = []
    total = 0
    for les in lessons:
        d = os.path.join(ROOT, les)
        files = sorted([f for f in os.listdir(d) if f.endswith(".c")], key=natural_key)
        items = []
        for f in files:
            with open(os.path.join(d, f), "r", encoding="utf-8", errors="replace") as fp:
                src = fp.read()
            src = src.replace("\t", "    ").replace("\r\n", "\n")
            items.append((f, src, len(src.split("\n"))))
        total += len(items)
        data.append((les, items))
        print(f"{les}: {len(items)} 个文件")

    doc = Document()

    # 页面设置
    sec = doc.sections[0]
    sec.page_width, sec.page_height = Cm(21.0), Cm(29.7)
    sec.left_margin = sec.right_margin = Cm(2.0)
    sec.top_margin = sec.bottom_margin = Cm(2.0)

    # 正文默认字体
    normal = doc.styles["Normal"]
    normal.font.name = "微软雅黑"
    normal.font.size = Pt(10.5)
    normal.element.rPr.rFonts.set(qn("w:eastAsia"), "微软雅黑")

    # 标题样式
    h1 = doc.styles["Heading 1"]
    h1.font.name = "微软雅黑"; h1.font.size = Pt(18); h1.font.bold = True
    h1.font.color.rgb = RGBColor(0x1F, 0x4E, 0x9C)
    h1.element.rPr.rFonts.set(qn("w:eastAsia"), "微软雅黑")

    h2 = doc.styles["Heading 2"]
    h2.font.name = "微软雅黑"; h2.font.size = Pt(12.5); h2.font.bold = True
    h2.font.color.rgb = RGBColor(0x2C, 0x3E, 0x50)
    h2.element.rPr.rFonts.set(qn("w:eastAsia"), "微软雅黑")

    # ---------- 封面 ----------
    for _ in range(4):
        doc.add_paragraph()
    t = doc.add_paragraph(); t.alignment = WD_ALIGN_PARAGRAPH.CENTER
    set_run(t.add_run("C 语言课程代码复习手册"), "微软雅黑", "微软雅黑", 30, RGBColor(0x1F, 0x4E, 0x9C), True)
    t2 = doc.add_paragraph(); t2.alignment = WD_ALIGN_PARAGRAPH.CENTER
    set_run(t2.add_run("lesson01 — lesson11 全部示例代码合集"), "微软雅黑", "微软雅黑", 14, C_SUB)
    t3 = doc.add_paragraph(); t3.alignment = WD_ALIGN_PARAGRAPH.CENTER
    set_run(t3.add_run(f"共 {len(lessons)} 讲 · {total} 个源文件 · 生成于 {datetime.now():%Y-%m-%d}"),
            "微软雅黑", "微软雅黑", 10.5, C_SUB)

    doc.add_paragraph()
    tip = doc.add_paragraph(); tip.alignment = WD_ALIGN_PARAGRAPH.CENTER
    set_run(tip.add_run("用法：在 Word 中打开“导航窗格”可按章节快速跳转；每个文件前有打卡方框，复习完可勾选。"),
            "微软雅黑", "微软雅黑", 9.5, C_SUB)

    # ---------- 总览 ----------
    doc.add_paragraph().add_run().add_break(WD_BREAK.PAGE)
    doc.add_heading("总览", level=1)
    tbl = doc.add_table(rows=1, cols=4)
    tbl.style = "Table Grid"
    tbl.alignment = WD_TABLE_ALIGNMENT.CENTER
    hdr = ["章节", "文件数", "主题（按文件名推断）", "复习进度"]
    widths = [Cm(2.6), Cm(1.8), Cm(9.0), Cm(3.0)]
    for i, h in enumerate(hdr):
        cell = tbl.rows[0].cells[i]
        cell.text = ""
        p = cell.paragraphs[0]
        set_run(p.add_run(h), "微软雅黑", "微软雅黑", 9.5, RGBColor(0xFF, 0xFF, 0xFF), True)
        shade(p, C_ACC)
    for les, items in data:
        row = tbl.add_row()
        cells = row.cells
        cells[0].text = ""; set_run(cells[0].paragraphs[0].add_run(les.replace("lesson", "Lesson ")), "微软雅黑", "微软雅黑", 9.5)
        cells[1].text = ""; set_run(cells[1].paragraphs[0].add_run(str(len(items))), "微软雅黑", "微软雅黑", 9.5)
        cells[2].text = ""
        set_run(cells[2].paragraphs[0].add_run("、".join(guess_topics([f for f, _, _ in items])) or "—"),
                "微软雅黑", "微软雅黑", 9.5)
        cells[3].text = ""; set_run(cells[3].paragraphs[0].add_run("☐ ☐ ☐ ☐ ☐"), "微软雅黑", "微软雅黑", 9.5)
    for row in tbl.rows:
        for i, w in enumerate(widths):
            row.cells[i].width = w

    # ---------- 各讲 ----------
    ctx = {"n": 0}
    for les, items in data:
        doc.add_heading(f"{les.replace('lesson', 'Lesson ')}（{len(items)} 个文件）", level=1)

        # 打卡清单
        idx = doc.add_table(rows=1, cols=3)
        idx.style = "Table Grid"
        for i, h in enumerate(["#", "文件名", "已复习"]):
            c = idx.rows[0].cells[i]; c.text = ""
            set_run(c.paragraphs[0].add_run(h), "微软雅黑", "微软雅黑", 9, RGBColor(0xFF, 0xFF, 0xFF), True)
            shade(c.paragraphs[0], C_ACC)
        for i, (f, src, lines) in enumerate(items, 1):
            r = idx.add_row().cells
            r[0].text = ""; set_run(r[0].paragraphs[0].add_run(str(i)), "微软雅黑", "微软雅黑", 9)
            r[1].text = ""; set_run(r[1].paragraphs[0].add_run(f), "Consolas", "微软雅黑", 8.5)
            r[2].text = ""; set_run(r[2].paragraphs[0].add_run("☐"), "微软雅黑", "微软雅黑", 9)
        for row in idx.rows:
            row.cells[0].width = Cm(1.0)
            row.cells[1].width = Cm(11.5)
            row.cells[2].width = Cm(2.0)

        doc.add_paragraph()
        for f, src, lines in items:
            doc.add_heading(f"{f}  ·  {lines} 行", level=2)
            add_code_block(doc, src, ctx)

    # ---------- 页脚 ----------
    footer = doc.sections[0].footer
    fp = footer.paragraphs[0]
    fp.alignment = WD_ALIGN_PARAGRAPH.CENTER
    set_run(fp.add_run("C 语言复习手册 · lesson01–lesson11    |    第 "), "微软雅黑", "微软雅黑", 8.5, C_SUB)
    set_run(add_field(fp, "PAGE"), "微软雅黑", "微软雅黑", 8.5, C_SUB)
    set_run(fp.add_run(" 页"), "微软雅黑", "微软雅黑", 8.5, C_SUB)

    doc.save(OUT)
    print("已生成:", OUT)


if __name__ == "__main__":
    build()
