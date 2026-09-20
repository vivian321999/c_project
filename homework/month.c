#include <stdio.h>

int monthDays(int year, int month);

int monthDays(int year, int month) {
    if (month < 1 || month > 12) {
        return -1;
    }

    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            return 29;
        }
        return 28;
    }

    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }

    return 31;
}

int main(void) {
    int T;
    int year, month;
    int days;

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d %d", &year, &month);

        days = monthDays(year, month);

        if (days < 0) {
            printf("Invalid month\n");
        } else {
            printf("%d\n", days);
        }
    }

    return 0;
}