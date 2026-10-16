/*pointer to array*/
#include <stdio.h>
#define N 3

int main(void) {
    int arr[][N] = {{1, 2, 3}, {2, 3}, {3}};
    int (*p)[N] = arr;  // 注意用括号，区别指针的数组
    // 解释为 int[] 类型的指针
    int i, j;
    for (i = 0; i < N; i++) {
        //        printf("*p[%d]=%d\n",i,*p[i]);
        for (j = 0; j < N - i; j++) printf("%4d", p[i][j]);
        printf("\n");
    }
    return 0;
}