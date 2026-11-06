/*struct definition*/
#include <stdio.h>

struct STUDENT {
    char id[6];
    char name[10];
    int age;
    // 任务1：去除 * 号 ，按 F12
    struct ADDRESS* home;
} john;

struct STUDENT anna;

struct ADDRESS {
    char area_id[6];
    char* details;
    char post_code[6];
    // 任务2：去除下面语句注释
    // struct STUDENT receiver;
};

struct CLASS {
    char id[10];
    int members;  // 结构体中不支持 VLA
    struct STUDENT* students;
};

struct CLASS c_class[6];

int main(void) {
    printf("hello");

    return 0;
}
