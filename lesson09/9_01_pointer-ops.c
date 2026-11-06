/*pointer ops*/
#include <stdio.h>

int main(void) {
    int a = 0;
    int* p = &a;
    *p = 10;
    printf("pointer p=%p, x=%p\n", (void*)p, (void*)p);  // a的地址
    printf("address &a=%p, &*p=%p\n", (void*)&a, (void*)&*p);  // a的地址
    printf("value *p=%d,a=%d\n", *p, a);         // a本身的值
    return 0;
}