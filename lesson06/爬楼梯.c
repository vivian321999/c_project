#include <stdio.h>

int climbStairs(int n) {
    int previous = 1;
    int current = 2;

    if (n == 1) {
        return previous;
    }

    for (int step = 3; step <= n; step++) {
        int next = previous + current;
        previous = current;
        current = next;
    }

    return current;
}

int main(void) {
    int n;

    if (scanf("%d", &n) == 1) {
        printf("%d\n", climbStairs(n));
    }

    return 0;
}
