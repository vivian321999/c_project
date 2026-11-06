/* struct-vs-union */
#include <stdio.h>
struct S {
    char a[3];
    int b;
}; /* 大小 8 */
union U {
    char a[3];
    int b;
}; /* 大小 4 */
int main(void) {
    struct S s;
    union U u;
    printf("struct: &a=%p, &b=%p, sizeof=%zu\n", (void*)&s.a, (void*)&s.b, sizeof s);  // 地址不同
    printf("union : &a=%p, &b=%p, sizeof=%zu\n", (void*)&u.a, (void*)&u.b, sizeof u);  // 地址相同

    u.b = 65;                        /* 写 int */
    printf("u.a[0] = %d\n", u.a[0]); /* 65：读到了同一块内存的低字节 */
    return 0;
}
