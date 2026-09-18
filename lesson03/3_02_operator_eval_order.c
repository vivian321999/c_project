/*operator eval order*/
#include <stdio.h>

int main() {
    int a = 4, b = 2, c = 3;

    printf("%d\n", a = b = c);      // a=3,b=3,c=3
    printf("%d\n", a = b == c);     // a=1,b=3,c=3
    printf("%d\n", a == (b = c));   // a=3,b=3,c=3
    printf("%d\n", a == (b == c));  // a=1,b=2,c=3

    return 0;
}