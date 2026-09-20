#include <stdio.h>

int main() {
    int m, n;
    int count = 0;
    int maxPrime = 0;

    scanf("%d %d", &m, &n);

    for (int x = m; x <= n; x++) {
        int isPrime = 1;

        for (int d = 2; d * d <= x; d++) {
            if (x % d == 0) {
                isPrime = 0;
                break;
            }
        }

        if (isPrime) {
            count++;
            maxPrime = x;
        }
    }

    printf("%d\n", count);
    printf("%d\n", maxPrime);

    return 0;
}