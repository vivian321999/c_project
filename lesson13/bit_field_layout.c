#include <stdio.h>

struct BF10 {
    int a : 4;  // 32 bits
} bit_field1;

struct BF11 {
    int a : 4, : 2, b : 5;  // 32 bits, how about a:3?
} bit_field2;

struct BF20 {
    int a : 4, : 2;  // 32 bits
    int b : 27;      // not enough, another 32 bit
} bit_field3;

struct BF21 {
    int a : 4, : 2, : 0;  // 32 bits
    int b : 4;            // another 32 bits due to :0
} bit_field4;

union {
    int i;
    struct BF11 bf11;  // cannot be coexist in a union
} u1 = {.i = 0x5a};

union {
    int i[2];
    struct BF21 bf21;  // cannot be coexist in a union
} u2 = {.i = {0x5a, 0x5a}};

int main(void) {
    printf("bit_field1 size %zu, start = %p\n", sizeof(bit_field1), (void*)&bit_field1);

    printf("bit_field2 size %zu, start = %p\n", sizeof(bit_field2), (void*)&bit_field2);

    printf("bit_field3 size %zu, start = %p\n", sizeof(bit_field3), (void*)&bit_field3);

    printf("bit_field4 size %zu, start = %p\n", sizeof(bit_field4), (void*)&bit_field4);

    printf("%x,%x\n", u1.bf11.a,
           u1.bf11.b);  // read 4 bits, skip 2 bits then add ones for a; read 5 bits for b
    printf("%x,%x\n", u2.bf21.a, u2.bf21.b);
}

// 0x5a: 0000 0000 0000 0000 0000 0000 0101 1010
