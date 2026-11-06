/*operator precedence*/
#include <stdio.h>
int main(void) {
    int a = 16, b = 4, c = 2;

    int d = a + b * c;
    int e = a / b * c;
    printf("d=%d, e=%d\n", d, e);

    return 0;
}