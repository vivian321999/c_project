/* struct-layout */
#include <stddef.h>
#include <stdio.h>

struct S1 {
    char a[3];
    int b;
    short c;
}; /* 默认对齐 */

#pragma pack(1)
struct S2 {
    char a[3];
    int b;
    short c;
};             /* 按 1 字节对齐 */
#pragma pack() /* 恢复默认，勿忘！ */

int main(void) {
    printf("sizeof(S1) = %zu\n", sizeof(struct S1)); /* 12 */
    printf("sizeof(S2) = %zu\n", sizeof(struct S2)); /* 9  */

    struct S1 s = {"ab", 1, 2};
    printf("a=%p b=%p c=%p\n", (void*)&s.a, (void*)&s.b, (void*)&s.c);
    printf("offset of b = %zu\n", offsetof(struct S1, b)); /* 4，跳过 1 字节填充 */
    return 0;
}