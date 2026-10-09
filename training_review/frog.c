#include <stdio.h>
long long step(int stairs) {
    if (stairs <= 0) return 0;
    if (stairs == 1) return 1;
    if (stairs == 2) return 2;
    return step(stairs - 1) + step(stairs - 2);
}
int main(void) {
    int steps;
    printf("请输入台阶数：");
    scanf("%d", &steps);
    if (steps < 0) {
        printf("不符合要求");
        return 0;
    } else {
        printf("%lld\n", step(steps));
    }
    return 0;
}