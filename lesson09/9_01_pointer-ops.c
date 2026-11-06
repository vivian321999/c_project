/*pointer ops*/
#include <stdio.h>

int main(void) {
    int a = 0;
    int* p = &a;
    *p = 10;
    printf("pointer p=%p, x=%x\n", p, p);        // a的地址
    printf("address &a=%p, &*p=%p\n", &a, &*p);  // a的地址
    printf("value *p=%d,a=%d\n", *p, a);         // a本身的值
    return 0;
}