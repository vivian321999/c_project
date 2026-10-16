#include <stdio.h>
#include <stdlib.h>

int* f(void) {
    int x = 1;
    return &x;  // 错：返回局部变量地址，x 销毁后成野指针
}

int main(void) {
    int* p;  // 错：未初始化，p 是野指针
    // printf("%d\n", *p);   // 未定义行为，可能段错误

    int* q = NULL;
    // printf("%d\n", *q);   // 错：解引用空指针，通常段错误

    int* r = malloc(sizeof(int));
    free(r);
    // printf("%d\n", *r);   // 错：free 后未置 NULL，r 是野指针

    int* s = f();
    // printf("%d\n", *s);   // 错：s 指向已销毁内存

    return 0;
}