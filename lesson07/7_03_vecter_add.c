/*vector add*/
#include <stdio.h>
#define LEN_ARR(a) (sizeof(a) / sizeof(a[0]))

void vadd(int a[const], const int b[], const size_t sz);

int main(void) {
    int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vadd(a, a, LEN_ARR(a));
    for (size_t i = 0; i < LEN_ARR(a); i++) {
        printf("%d,", a[i]);
    }
    printf("\n");
}

void vadd(int a[const], const int b[], const size_t sz) {
    for (size_t i = 0; i < sz; i++) {
        a[i] += b[i];
        //        a++; //increment of read-only parameter 'a'
        //        b[i] = 1;  //assignment of read-only location
    }
}
