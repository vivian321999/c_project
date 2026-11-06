#include <stdio.h>

int main(void) {
    double a, b;
    scanf("%lf,%lf", &a, &b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("a=%lf,b=%lf\n", a, b);
    return 0;
}
