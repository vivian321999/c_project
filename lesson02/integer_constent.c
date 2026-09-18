#include <stdio.h>

int main() {
    int a = 10;
    int b = 012;
    int c = 0x10;

    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);
    printf("%o\n", b);
    printf("%x\n", c);
    return 0;
}