/* pointer-as-parameter */
#include <stdio.h>
// 开头void 表示函数没有返回值
void swap_wrong(int x, int y) { /* 只交换副本，实参不变 */
    int t = x;
    x = y;
    y = t;
}

void swap(int* px, int* py) { /* 形参接收地址 */
    int t = *px;
    *px = *py;
    *py = t;
}

void divmod(int a, int b, int* q, int* r) { /* 输出参数 */
    *q = a / b;
    *r = a % b;
}

int main(void) {
    int a = 3, b = 5;
    // 调用swap_wrong函数，无法交换a和b的值
    swap_wrong(a, b);
    printf("wrong: a=%d b=%d\n", a, b);
    // 调用swap函数，可以交换a和b的值
    swap(&a, &b);
    printf("right: a=%d b=%d\n", a, b);
    // 调用divmod函数，计算17除以5的商和余数
    int q, r;
    divmod(17, 5, &q, &r);
    printf("17 / 5 = %d ... %d\n", q, r);
    return 0;
}
