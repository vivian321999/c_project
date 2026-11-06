/*array of pointers*/
#include <stdio.h>
#define N 3

int main(void) {
    int arr[N] = {1, 2, 3};  // 定义一个整型数组
    int* p[N] = {NULL};      // 定义一个指针数组，元素类型是int*，数组大小为N

    for (int i = 0; i < N; i++) {
        p[i] = &arr[i];  // 将指针数组的每个元素指向arr数组的对应元素
    }
    for (int i = 0; i < N; i++) {
        // 遍历指针数组的每个元素
        printf("*p[%d]=%d\n", i, *p[i]);
        // 遍历指针数组的每个元素所指向的数组元素
        for (int j = 0; j < N - i; j++) {
            printf("%4d", p[i][j]);
            // 通过指针访问数组元素，%4d表示输出宽度为4的整数
        }
        printf("\n");
    }
    return 0;
}

// 此处p[i][j]的含义是：p[i]是一个指针，指向arr数组的第i个元素，而p[i][j]表示访问arr数组中第i个元素之后的第j个元素，即arr[i
// + j].