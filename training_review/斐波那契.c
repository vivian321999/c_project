#include <stdio.h>
long long func(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1;
    return func(n - 1) + func(n - 2);
}
int main(void) {
    int m;
    printf("请输入项数：");
    scanf("%d", &m);
    if (m <= 0) {
        printf("不符合要求");
        return 0;
    } else {
        printf("%lld\n", func(m));
    }

    printf("前%d项斐波那契数列:\n", m);
    for (int i = 1; i <= m; i++) {
        printf("%lld\n", func(i));
    }
    return 0;
}