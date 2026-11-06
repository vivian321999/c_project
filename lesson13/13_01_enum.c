#include <stdio.h>
#include <string.h>

typedef enum { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC } MONTHS;

enum checks { A = 0 };  // 全局定义枚举类，定义了整数常数 A
// enum checks1{A = 1};//那么无法在全局中再定义整数常数 A
// enum checks1{A = 0};//无法在全局中再定义枚举常量

int main(void) {
    MONTHS m;  // m是一个整数
    for (m = JAN; m < JUL; m++) printf("%d", m);

    enum checks ck;
    ck = 3;
    printf("\n%d\n", ck);

    return 0;
}
