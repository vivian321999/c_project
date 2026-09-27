#include <math.h>
#include <stdio.h>

int isPrime(unsigned int n);

int main() {
    // test case
    int n = 2;  // 3,5,8,11,15
    printf("%d\n", isPrime(n));
}

int isPrime(unsigned int n) {
    int out = 1;
    if (n < 2) return 0;
    for (int i = 2; i <= n; i++) {
        if (!(n / i)) {
            out = 0;
            break;
        }
    }
    return out;
}