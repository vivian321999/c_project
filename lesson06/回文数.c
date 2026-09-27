#include <stdbool.h>
#include <stdio.h>

bool isPalindrome(int x) {
    int reversed_half = 0;

    if (x < 0 || (x != 0 && x % 10 == 0)) {
        return false;
    }

    while (x > reversed_half) {
        reversed_half = reversed_half * 10 + x % 10;
        x /= 10;
    }

    return x == reversed_half || x == reversed_half / 10;
}

int main(void) {
    int x;

    if (scanf("%d", &x) == 1) {
        printf("%s\n", isPalindrome(x) ? "true" : "false");
    }

    return 0;
}
