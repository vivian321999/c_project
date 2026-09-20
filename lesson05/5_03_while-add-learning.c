/*while-add-learning*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // give seed
    srand((unsigned)time(NULL));  // seed

    int i, j, sum;
    bool flag = true;  // 标志变量

    while (flag) {
        i = rand() % 10;
        j = rand() % 10;

        printf("%d + %d = ", i, j);
        scanf("%d", &sum);

        if (i + j == sum)
            printf("恭喜你，答对了！\n");
        else
            printf("Oooops，再努力一次。\n");

        char c = getchar();
        if (c == 'q' || c == 'Q') flag = false;
    }
    return 0;
}