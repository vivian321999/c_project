/*ops arithmetic int promotion*/
#include <stdio.h>

int main(void) {
    char i, j;
    /*请分别输入 1，2，100，129*/
    scanf("%hhd", &i);
    j = 255 * i;
    printf("%d,%d,%0x\n", j, 255 * i, 255 * i);
}