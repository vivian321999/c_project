/*pointer to array*/
#include <stdio.h>
#define N 3

int main(void) {
    int arr[][N] = {{1, 2, 3}, {2, 3}, {3}};  // 定义一个二维数组
    int (*p)[N] = arr;                        // 指向数组的指针
    // 解释为 int[] 类型的指针
    int i, j;
    for (i = 0; i < N; i++) {
        // 遍历数组的每一行
        printf("*p[%d]=%d\n", i, *p[i]);
        // 遍历数组的每一列
        for (j = 0; j < N - i; j++) {
            printf("%4d", p[i][j]);  // 通过指针访问数组元素，%4d表示输出宽度为4的整数
        }
        printf("\n");
    }
    return 0;
}
