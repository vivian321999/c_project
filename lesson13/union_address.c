#include <stdio.h>

union Rational {
    int x;
    double y;
};

int main(void) {
    union Rational temp;

    temp.x = 100;

    //    printf("%p\n", &temp);
    //    printf("%p\n", &temp.x);
    //    printf("%p\n", &temp.y);

    printf("%d\n", temp.x);
    printf("%f\n", temp.y);
}
