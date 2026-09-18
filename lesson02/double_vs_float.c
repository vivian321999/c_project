#include <stdio.h>

int main() {
    float a = 1.23456789012345f;
    double b = 1.23456789012345;

    printf("%.15f\n", a);
    printf("%.15f\n", b);

    return 0;
}