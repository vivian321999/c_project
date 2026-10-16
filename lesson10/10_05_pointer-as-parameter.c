/* pointer-as-parameter */
#include <stdio.h>

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

int main() {
    int a = 3, b = 5;
    swap_wrong(a, b);
    printf("wrong: a=%d b=%d\n", a, b);
    swap(&a, &b);
    printf("right: a=%d b=%d\n", a, b);
    int q, r;
    divmod(17, 5, &q, &r);
    printf("17 / 5 = %d ... %d\n", q, r);
    return 0;
}
