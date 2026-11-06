#include <stdio.h>
#include <stdlib.h>

int** generateMatrix(int n, int* size, int** colSizes) {
    // 分配n行指针
    int** matrix = (int**)malloc(n * sizeof(int*));

    // 设置返回参数
    *size = n;                                  // 矩阵有n行
    *colSizes = (int*)malloc(n * sizeof(int));  // 每行的列数

    // 初始化矩阵，分配每行的空间并设置列数
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
        (*colSizes)[i] = n;  // n x n矩阵，每行都有n列
    }

    if (n == 0) return matrix;

    int num = 1;                  // 要填充的数字，从1开始
    int top = 0, bottom = n - 1;  // 上下边界
    int left = 0, right = n - 1;  // 左右边界

    while (num <= n * n) {
        // 从左到右填充上边界
        for (int i = left; i <= right && num <= n * n; i++) {
            matrix[top][i] = num++;
        }
        top++;

        // 从上到下填充右边界
        for (int i = top; i <= bottom && num <= n * n; i++) {
            matrix[i][right] = num++;
        }
        right--;

        // 从右到左填充下边界
        for (int i = right; i >= left && num <= n * n; i--) {
            matrix[bottom][i] = num++;
        }
        bottom--;

        // 从下到上填充左边界
        for (int i = bottom; i >= top && num <= n * n; i--) {
            matrix[i][left] = num++;
        }
        left++;
    }

    return matrix;
}

int main(void) {
    int n = 6;

    int size, *colSizes;
    int** matrix = generateMatrix(n, &size, &colSizes);

    printf("螺旋矩阵 %dx%d:\n", n, n);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < colSizes[i]; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    // 释放内存
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(colSizes);

    return 0;
}
