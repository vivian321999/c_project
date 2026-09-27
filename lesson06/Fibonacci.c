#include <stdio.h>

int fib(int n) {
    // 基准情况
    if (n == 0) return 0;
    if (n == 1) return 1;

    // 递归调用
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;

    printf("请输入n值: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("n不能为负数\n");
        return 1;
    }

    printf("F(%d) = %d\n", n, fib(n));

    // 打印前n项斐波那契数列
    printf("前%d项斐波那契数列: ", n + 1);
    for (int i = 0; i <= n; i++) {
        printf("%d ", fib(i));
    }
    printf("\n");

    return 0;
}