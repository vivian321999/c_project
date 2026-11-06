#include <stdio.h>

#pragma pack(1)

typedef union {
    char a[3];
    int b;
    short c;
} packed_struct;

#pragma pack(4)

typedef union {
    char a[3];
    int b;
    short c;
} unpacked_struct;

// 千万别忘了
// 设置当前对齐为默认值
#pragma pack()
// 否则会导致程序性能大幅下降

int main(void) {
    packed_struct ps;
    ps.a[0] = 00;
    ps.a[1] = 11;
    ps.a[2] = 22;
    ps.b = 33445566;
    ps.c = 7788;

    unpacked_struct ups;
    ups.a[0] = 00;
    ups.a[1] = 11;
    ups.a[2] = 22;
    ups.b = 33445566;
    ups.c = 7788;

    printf("sizeof packed_struct %ld\n", sizeof(packed_struct));
    printf("sizeof unpacked_struct %ld\n", sizeof(unpacked_struct));
}
