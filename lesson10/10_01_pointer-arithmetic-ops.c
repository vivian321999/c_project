/*pointer-arithmetic-ops */
#include <stdio.h>

int main(void) {
    int arr[] = {0, 1, 2, 3, 4, 5};
    // 定义一个整型数组
    int* p = arr;
    // 定义一个指针p，指向arr数组的首元素
    int* q = &arr[sizeof(arr) / sizeof(int)];
    // 定义一个指针q，指向arr数组的最后一个元素的下一个位置
    printf("q-p=%ld\n", q - p);
    // 输出q和p之间的元素个数，即arr数组的长度
    printf("sizeof(arr)=%ld\n", sizeof(arr));
    // 输出arr数组的总字节数
    printf("sizeof(int)=%ld\n", sizeof(int));
    // 输出int类型的字节数
    for (; p < q; p++) {
        printf("%d", *p);
        // 输出指针p所指向的数组元素
    }
    printf("\n");
    for (q = q - 1; q >= arr; q--) {
        printf("%d", *q);
        // 输出指针q所指向的数组元素，从最后一个元素开始输出
    }
    printf("\n");
    return 0;
}
// 正序和倒序输出数组元素，使用指针进行遍历。