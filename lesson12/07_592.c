#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 结构体封装分数：分子 / 分母 */
typedef struct {
    int num; /* numerator   */
    int den; /* denominator */
} Fraction;

/* 最大公约数 */
int gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

/* 分数加法：用 const 指针传参，避免结构体拷贝 */
Fraction fractionAdd(const Fraction* a, const Fraction* b) {
    Fraction r;

    /* a/b + c/d = (a*d + c*b) / (b*d) */
    r.num = a->num * b->den + b->num * a->den;
    r.den = a->den * b->den;

    /* 立即约分，防止数值膨胀 */
    int g = gcd(r.num, r.den);
    r.num /= g;
    r.den /= g;

    /* 分母保持为正，符号放在分子上 */
    if (r.den < 0) {
        r.num = -r.num;
        r.den = -r.den;
    }
    return r;
}

/* LeetCode 592 核心函数 */
char* fractionAddition(char* expression) {
    Fraction fractions[20];
    int count = 0;
    int i = 0;
    int len = strlen(expression);

    /* 1. 解析表达式，存入结构体数组 */
    while (i < len) {
        int sign = 1;

        /* 首项正号可省略；后续项读取 +/- */
        if (expression[i] == '+' || expression[i] == '-') {
            sign = (expression[i] == '-') ? -1 : 1;
            i++;
        }

        int num = 0;
        while (i < len && isdigit(expression[i])) {
            num = num * 10 + (expression[i] - '0');
            i++;
        }

        if (i < len && expression[i] == '/') i++;

        int den = 0;
        while (i < len && isdigit(expression[i])) {
            den = den * 10 + (expression[i] - '0');
            i++;
        }

        fractions[count].num = sign * num;
        fractions[count].den = den;
        count++;
    }

    /* 2. 依次累加，结构体可整体赋值 */
    Fraction result = fractions[0];
    for (int j = 1; j < count; j++) {
        result = fractionAdd(&result, &fractions[j]);
    }

    /* 3. 输出最简分数 */
    char* out = (char*)malloc(64);
    sprintf(out, "%d/%d", result.num, result.den);
    return out;
}

/* 本地测试入口 */
int main(void) {
    char expression[256];

    if (scanf("%255s", expression) == 1) {
        char* ans = fractionAddition(expression);
        printf("%s\n", ans);
        free(ans);
    }

    return 0;
}
