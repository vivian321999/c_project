#include <stdio.h>
#include <stdlib.h>

#define mkList(i, l, new)                                \
    struct List* new;                                    \
    {                                                    \
        new = (struct List*)malloc(sizeof(struct List)); \
        new->n = i;                                      \
        new->next = l;                                   \
    }

struct List {
    int n;
    struct List* next;
};

// Get length
int length(struct List* l) {
    if (l == NULL) {
        return 0;
    } else {
        return 1 + length(l->next);
    }
}

// Add node
struct List* append(struct List* l, int n) {
    if (l == NULL) {
        mkList(n, l, res);
        return res;
    } else {
        mkList(l->n, append(l->next, n), res);
        return res;
    }
}

// Reverse the linked list
struct List* reverse(struct List* l) {
    if (l == NULL) {
        return NULL;
    } else {
        return append(reverse(l->next), l->n);
    }
}

int main(void) {
    struct List l = {3, NULL};
    struct List l2 = {2, &l};
    struct List l3 = {1, &l2};

    struct List* p;
    int j;

    int len = length(&l3);
    printf("The length of the linked list is: %d\n", len);

    p = &l3;
    j = 1;
    printf("Original linked list\n");
    while (p != NULL) {
        printf("%5d%10d\n", j, p->n);
        p = p->next;
        j++;
    }

    p = reverse(&l3);
    j = 1;
    printf("Reversed linked list\n");
    while (p != NULL) {
        printf("%5d%10d\n", j, p->n);
        p = p->next;
        j++;
    }

    p = &l3;
    p = append(p, 4);
    j = 1;
    printf("Adding a node to linked list\n");
    while (p != NULL) {
        printf("%5d%10d\n", j, p->n);
        p = p->next;
        j++;
    }

    return 0;
}
