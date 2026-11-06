#include <stdio.h>
#include <stdlib.h>
struct link* AppendNode(struct link* head);
void DisplyNode(struct link* head);
void DeleteMemory(struct link* head);
struct link* InsertNode(struct link* head, int nodeData);

struct link {
    int data;
    struct link* next;
};
int main(void) {
    int i = 0;
    char c;
    struct link* head = NULL; /* 链表头指针 */
    printf("Do you want to append a new node(Y/N)?");
    scanf(" %c", &c); /* %c前面有一个空格 */
    while (c == 'Y' || c == 'y') {
        head = AppendNode(head);
        DisplyNode(head); /* 显示当前链表中的各节点信息 */
        printf("Do you want to append a new node(Y/N)?");
        scanf(" %c", &c); /* %c前面有一个空格 */
        i++;
    }
    printf("%d new nodes have been apended!\n", i);
    head = InsertNode(head, 20);
    DisplyNode(head);
    DeleteMemory(head); /* 释放所有动态分配的内存 */
    return 0;
}
/* 函数功能：新建一个节点并添加到链表末尾，返回添加节点后的链表的头指针 */
struct link* AppendNode(struct link* head) {
    struct link* p = NULL;
    struct link* pr = head;
    int data;
    p = (struct link*)malloc(sizeof(struct link)); /* 让p指向新建节点 */
    if (p == NULL) {
        printf("No enough memory to allocate!\n");
        exit(0);
    }
    if (head == NULL) /* 若原链表为空表，则将新建节点置为首节点 */
    {
        head = p;
    } else /* 若原链表为非空，则将新建节点添加到表尾 */
    {
        while (pr->next != NULL) /* 若未到表尾，则移动pr直到pr指向表尾 */
        {
            pr = pr->next; /* 让pr指向下一个节点 */
        }
        pr->next = p; /* 将新建节点添加到链表的末尾 */
    }
    pr = p; /* 让pr指向新建节点 */
    printf("Input node data:");
    scanf("%d", &data); /* 输入节点数据 */
    pr->data = data;
    pr->next = NULL; /* 将新建节点置为表尾 */
    return head;     /* 返回添加节点后的链表的头节点指针 */
}
/* 	函数的功能：显示链表中所有节点的节点号和该节点中数据项内容 */
void DisplyNode(struct link* head) {
    struct link* p = head;
    int j = 1;
    while (p != NULL) /* 若不是表尾，则循环打印 */
    {
        printf("%5d%10d\n", j, p->data); /* 打印第j个节点的数据 */
        p = p->next;                     /* 让p指向下一个节点 */
        j++;
    }
}
/*	函数功能：释放head指向的链表中所有节点占用的内存 */
void DeleteMemory(struct link* head) {
    struct link *p = head, *pr = NULL;
    while (p != NULL) /* 若不是表尾，则释放节点占用的内存 */
    {
        pr = p;      /* 在pr中保存当前节点的指针 */
        p = p->next; /* 让p指向下一个节点 */
        free(pr);    /* 释放pr指向的当前节点占用的内存 */
    }
}
/* 函数功能：在已按升序排序的链表中插入一个节点，返回插入节点后的链表头指针 */
struct link* InsertNode(struct link* head, int nodeData) {
    struct link *pr = head, *p = head, *temp = NULL;
    p = (struct link*)malloc(sizeof(struct link)); /* 让p指向待插入节点 */
    if (p == NULL)                                 /* 若为新建节点申请内存失败，则退出程序 */
    {
        printf("No enough memory!\n");
        exit(0);
    }
    p->next = NULL;     /* 为待插入节点的指针域赋值为空指针 */
    p->data = nodeData; /* 为待插入节点数据域赋值为nodeData */
    if (head == NULL)   /* 若原链表为空表 */
    {
        head = p; /* 待插入节点作为头节点 */
    } else {      /* 若未找到待插入节点的位置且未到表尾，则继续找 */
        while (pr->data < nodeData && pr->next != NULL) {
            temp = pr;     /* 在temp中保存当前节点的指针 */
            pr = pr->next; /* pr指向当前节点的下一节点 */
        }
        if (pr->data >= nodeData) {
            if (pr == head) /* 若在头节点前插入新节点 */
            {
                p->next = head; /* 将新节点的指针域指向原链表的头节点 */
                head = p;       /* 让head指向新节点 */
            } else              /* 若在链表中间插入新节点 */
            {
                pr = temp;
                p->next = pr->next; /* 将新节点的指针域指向下一节点 */
                pr->next = p;       /* 让前一节点的指针域指向新节点 */
            }
        } else /* 若在表尾插入新节点 */
        {
            pr->next = p; /* 让末节点的指针域指向新节点 */
        }
    }
    return head; /* 返回插入新节点后的链表头指针head的值 */
}
