/*call by ref swap*/
#include <stdio.h>

void Swap(int* x, int* y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void NoSwap(int x, int y) {
    int t = x;
    x = y;
    y = t;
}

int main() {
    int a = 1, b = 3;
    printf("Before swapping: %d %d\n", a, b);
    Swap(&a, &b);
    printf("After swapping: %d %d\n", a, b);
    NoSwap(a, b);
    printf("After NoSwap: %d %d\n", a, b);
}