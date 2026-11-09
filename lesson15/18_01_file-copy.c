#include <stdio.h>

int FileCopy(const char* dest, const char* src);

int main(void) { return FileCopy("1复制.txt", "1.txt"); }

int FileCopy(const char* dest, const char* src) {
    char buf[1024 * 4];

    FILE* s = fopen(src, "rb");
    if (!s) {
        perror("打开源文件失败");
        return -1;
    }

    FILE* d = fopen(dest, "wb");
    if (!d) {
        perror("打开目标文件失败");
        fclose(s);
        return -1;
    }

    size_t cnt;
    size_t total = 0;
    while ((cnt = fread(buf, 1, sizeof(buf), s)) > 0) {
        if (fwrite(buf, 1, cnt, d) != cnt) {
            perror("写入目标文件失败");
            fclose(s);
            fclose(d);
            return -1;
        }
        total += cnt;
    }

    if (ferror(s)) {
        perror("读取源文件失败");
        fclose(s);
        fclose(d);
        return -1;
    }

    fclose(s);
    if (fclose(d) == EOF) {
        perror("关闭目标文件失败");
        return -1;
    }

    printf("文件复制成功：%s -> %s，共 %zu 字节\n", src, dest, total);
    return 0;
}
