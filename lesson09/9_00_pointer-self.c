/* pointer-self */
#include <stdio.h>
int main(void) {
    int a = 10;
    int* p = &a;  // 指针p指向a的地址
    printf("a的值        : %d\n", a);
    printf("a的地址      : %p\n", (void*)&a);
    printf("p的值(指向a) : %p\n", (void*)p);
    printf("p的地址      : %p\n", (void*)&p);
    printf("*p的值       : %d\n", *p);
    printf("sizeof(p)    : %zu 字节\n", sizeof(p));
    printf("sizeof(*p)   : %zu 字节\n", sizeof(*p));
    return 0;
}
