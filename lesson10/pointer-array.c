/*pointer array*/
#include <stdio.h>

int main() {
    int m[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int (*p)[4] = m;  // 指向数组类型数据的指针
    int i, j;
    for (i = 0; i < 3; i++) printf("%x,%x\n", p[i], m[i]);

    int*(mp[3])  //(指向数组的)指针的数组
        = {m[0], m[1], m[2]};

    for (i = 0; i < 3; i++) printf("%x\n", mp[i]);

    int** pp = mp;  //(指向)指针(数组)的指针
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) printf("%-4d", pp[i][j]);  // p[i][j], mp[i][j], pp[i][j]
        printf("\n");
    }
    return 0;
}