#include <limits.h>
#include <stdio.h>

int reverse(int x) {
    int result = 0;

    while (x != 0) {
        int digit = x % 10;
        x /= 10;

        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
            return 0;
        }
        if (result < INT_MIN / 10 || (result == INT_MIN / 10 && digit < INT_MIN % 10)) {
            return 0;
        }

        result = result * 10 + digit;
    }

    return result;
}

int main(void) {
    int x;

    if (scanf("%d", &x) == 1) {
        printf("%d\n", reverse(x));
    }

    return 0;
}
