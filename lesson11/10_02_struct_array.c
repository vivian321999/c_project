/* struct-array */
#include <stdio.h>
typedef struct {
    char id[6];
    char name[10];
    int age;
} Student;
int main(void) {
    Student cls[3] = {
        {"0101", "anna", 19}, {"0102", "bob", 20}, {"0103", "cindy", 18}}; /* 嵌套花括号初始化 */

    Student tmp = cls[0];
    cls[0] = cls[1]; /* 结构体元素整体赋值，合法 */
    cls[2] = tmp;

    double sum = 0;
    for (int i = 0; i < 3; i++) {
        printf("%s %s %d\n", cls[i].id, cls[i].name, cls[i].age);
        sum += cls[i].age;
    }
    printf("average age = %.1f\n", sum / 3);
    return 0;
}
/* 输出：cindy 18 / bob 20 / anna 19 / average age = 19.0 */
