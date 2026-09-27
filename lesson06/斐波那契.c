#include <stdio.h>

int fib(int n) {
    int previous = 0;
    int current = 1;

    for (int i = 0; i < n; i++) {
        int next = previous + current;
        previous = current;
        current = next;
    }

    return previous;
}

int main(void) {
    int n;

    if (scanf("%d", &n) == 1) {
        printf("%d\n", fib(n));
    }

    return 0;
}
