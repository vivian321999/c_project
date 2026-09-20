#include <stdio.h>
int main(void) {
    int n;
    int value;
    long long sum = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        sum += value;
    }

    printf("%lld %.5f\n", sum, (double)sum / n);

    return 0;
}