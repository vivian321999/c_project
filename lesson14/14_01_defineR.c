#include "stdio.h"
#define Pi 3.1415926 /*宏定义，用 Pi 代表字符串“3.1415926”  */
int main(void) {
    int r = 4;
    float i, s, v;
    i = 2 * Pi * r;               /*等价于 i = 2*3.1415926*r; */
    s = Pi * r * r;               /*等价于 s = 3.1415926*r*r; */
    v = 4.0 / 3 * Pi * r * r * r; /*等价于v=4.0/3*3.1415926*r*r*r; */
    printf("i=%f\ns=%f\nv=%f\n", i, s, v);
}
