/*array of pointers*/
#include <stdio.h>
#define N 3

int main() {
    int arr[N] = {1, 2, 3};
    int* p[N] = {};  //'[] () . ->' 取成员运算符高于其他一元运算符
    // 解释为 int * 类型的数组
    int i, j;
    for (i = 0; i < N; i++) p[i] = &arr[i];
    for (i = 0; i < N; i++) {
        //        printf("*p[%d]=%d\n",i,*p[i]);
        for (j = 0; j < N - i; j++) printf("%4d", p[i][j]);
        printf("\n");
    }
    return 0;
}