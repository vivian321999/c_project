/*void-parameter*/
#include <assert.h>
#include <stdio.h>
#include <string.h>

void* MemRepeat(void* dest, void* src, size_t src_sz, size_t count);
void Printx(void* p, size_t bytes_count);

int main() {
    int a[10], d = 7;
    float b[10], e = 3.14;

    MemRepeat(a, &d, sizeof(d), 10);
    int i;
    for (i = 0; i < 10; i++) printf("%6d", a[i]);
    printf("\n");

    MemRepeat(b, &e, sizeof(e), 10);
    for (i = 0; i < 10; i++) printf("%6.2lf", b[i]);
    printf("\n");

    Printx(&d, sizeof(d));
    Printx(&e, sizeof(e));
}

void* MemRepeat(void* dest, void* src, size_t src_sz, size_t count) {
    assert(dest && src);
    void* p = dest;
    int i;
    for (i = 0; i < count; i++) {
        memcpy(p, src, src_sz);
        p += src_sz;
        //        src += src_sz;
    }
    return dest;
}

void Printx(void* p, size_t bytes_count) {
    assert(p);
    int i;
    for (i = 0; i < bytes_count; i++, p++) printf("%4x", *(unsigned char*)p);
    printf("\n");
}

// 3.14
// 11.001000 11110101 11000011
// 01000000 01001000 11110101 11000011
