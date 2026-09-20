/*switch score to grade*/
#include <stdio.h>

int main() {
    int score;
    scanf("%d", &score);
    switch (score / 10) {
        case 10:
        case 9:
            printf("优秀\n");
            break;
        case 8:
            printf("良好\n");
            break;
        case 7:
        case 6:
            printf("及格\n");
            break;
        default:
            printf("你挂科啦!\n");
    }
}