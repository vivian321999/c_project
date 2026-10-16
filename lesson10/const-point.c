/*const point*/
#include <stdio.h>

int main() {
    const int n = 1;  // const 类型对象
                      //    n = 2; // 错误： n 的类型为 const 限定
    int x = 2;        // 无限定类型对象
    const int* p = &x;
    //    *p = 3; // 错误：左值 *p 的类型为 const 限定
    //    x = 3;
    //    p = &n;
    int* const q = &x;
    *q = 3;
    //    q = NULL;  // 错误：指针 q 的类型为 const 限定

    int* p1 = 0;
    const int* a = p1;  // 非 const 可隐式转为 const
                        //    p1 = a; // 错误：舍弃限定符（ const int 到 int ）
    p1 = (int*)a;       // const 赋予 非 const 必须显式转型

    return 0;
}