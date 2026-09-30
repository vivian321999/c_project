#include <stdio.h>

int FacterialLoop(int);
int FacterialRecursive(int);

int FacterialLoop(int n) {
    int m = 1;
    if (n == 1) {
        return 1;
    }
    for (int i = n; i >= 1; i--) {
        m *= i;
    }
    return m;
}

int FacterialRecursive(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n * FacterialLoop(n - 1);
    }
}
int main(void) {
    int n = 5;
    printf("loop out %d\n", FacterialLoop(n));
    printf("recursive out %d\n", FacterialRecursive(n));
}