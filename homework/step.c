#include <stdio.h>

int f(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    if (n == 3) {
        return 4;
    }

    int a = 1, b = 2, c = 4;
    int d;

    for (int i = 4; i <= n; i++) {
        d = a + b + c;
        a = b;
        b = c;
        c = d;
    }

    return c;
}

int main(void) {
    int T, n;

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d", &n);
        printf("%d\n", f(n));
    }

    return 0;
}