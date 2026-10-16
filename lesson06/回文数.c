#include <stdio.h>

int main(void) {
    int a;
    int b;
    int number;
    int original;
    int reversed;
    int count = 0;

    if (scanf("%d%d", &a, &b) == 2) {
        for (number = a; number <= b; number++) {
            original = number;
            reversed = 0;

            while (number > 0) {
                reversed = reversed * 10 + number % 10;
                number /= 10;
            }

            if (original == reversed) {
                count++;
            }

            number = original;
        }

        printf("%d\n", count);
    }

    return 0;
}
