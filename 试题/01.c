#include <stdio.h>
#include <string.h>

#define MAX_DOMAINS 10
#define MAX_DOMAIN_LENGTH 31
#define MAX_EMAIL_LENGTH 51

static int is_white_domain(const char *domain, char white[][MAX_DOMAIN_LENGTH],
                            int count) {
    for (int i = 0; i < count; i++) {
        if (strcmp(domain, white[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

static int is_black_domain(const char *domain, char black[][MAX_DOMAIN_LENGTH],
                           int count) {
    size_t domain_length = strlen(domain);

    for (int i = 0; i < count; i++) {
        size_t black_length = strlen(black[i]);

        if (strcmp(domain, black[i]) == 0) {
            return 1;
        }
        if (domain_length > black_length &&
            domain[domain_length - black_length - 1] == '.' &&
            strcmp(domain + domain_length - black_length, black[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main(void) {
    char white[MAX_DOMAINS][MAX_DOMAIN_LENGTH];
    char black[MAX_DOMAINS][MAX_DOMAIN_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    int white_count;
    int black_count;
    int email_count;

    scanf("%d", &white_count);
    for (int i = 0; i < white_count; i++) {
        scanf("%30s", white[i]);
    }

    scanf("%d", &black_count);
    for (int i = 0; i < black_count; i++) {
        scanf("%30s", black[i]);
    }

    scanf("%d", &email_count);
    for (int i = 0; i < email_count; i++) {
        char *at = NULL;
        int at_count = 0;

        scanf("%50s", email);
        for (char *current = email; *current != '\0'; current++) {
            if (*current == '@') {
                at = current;
                at_count++;
            }
        }

        if (at_count != 1 || at == email || *(at + 1) == '\0') {
            printf("Invalid\n");
            continue;
        }

        if (is_white_domain(at + 1, white, white_count)) {
            printf("White\n");
        } else if (is_black_domain(at + 1, black, black_count)) {
            printf("Black\n");
        } else {
            printf("Other\n");
        }
    }

    return 0;
}
