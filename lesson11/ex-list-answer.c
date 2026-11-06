#include <stdio.h>
#include <stdlib.h>

#include "node.h"

// 练习3：给出下面两个函数的实现，包括描述、实现和测试
NODE_PTR ListReverse(NODE_PTR li);
NODE_PTR ListFind(NODE_PTR li, int i);
// 你也可以适当修改以上声明

void printList(NODE_PTR li) {
    NODE_PTR p;
    for (p = li; p; p = p->next) printf("%d,", p->customerData);
    printf("\n");
}

/**************
删除指定位置的元素

参数：
    li 指向要删除元素的指针的指针
    通常是子链表 e.next 或 链表头 p 的指针
返回值：
    删除元素后的子链表指针
**************/
NODE_PTR ListDelete(NODE_PTR* li) {  // 此处**li = &list
    *li = ListRemove(*li);           // 此处*li为list
    return *li;
}

/***********
练习1：给出函数描述
***********/
NODE_PTR ListInsert(NODE_PTR* li, int i) {  // 此处**li = &list
    // 给出函数实现

    *li = ListAdd(*li, i);  // 此处*li为list, *li = np;
    return *li;  // *li and list have same memory, change *li will change the value of list
}

NODE_PTR ListInsertTest(NODE_PTR li, int i) {  // 此处*li = list
    // 给出函数实现

    li = ListAdd(li, i);  // 此处li为list, li = np;
    return li;  // li is a local variable and cannot change the value of list (outside the function)
}

int main(void) {
    NODE_PTR list = NULL;
    int i;
    for (i = 0; i < 10; i++) list = ListAdd(list, i + 1);
    // output is 10,9,8,7,6,5,4,3,2,1,
    printList(list);

    // place your code here, for example
    ListInsert(&list, 11);
    // output is 11,10,9,8,7,6,5,4,3,2,1,
    printList(list);
    NODE_PTR p = ListIndex(list, 3);
    ListInsert(&p->next, 12);
    // output is 11,10,9,8,12,7,6,5,4,3,2,1,
    printList(list);
    // p = ListInsertTest(p->next,12);
    // output is 12,7,6,5,4,3,2,1,
    //  printList(p);

    p = ListIndex(list, ListLength(list) - 1);
    ListInsert(&p->next, 13);
    // output is 11,10,9,8,12,7,6,5,4,3,2,1,13,
    printList(list);

    p = ListIndex(list, ListLength(list) - 2);
    ListDelete(&p->next);
    // output is 11,10,9,8,12,7,6,5,4,3,2,1,
    printList(list);
    p = ListIndex(list, 3);
    ListDelete(&p->next);
    // output is 11,10,9,8,7,6,5,4,3,2,1,
    printList(list);
    ListDelete(&list);
    // 练习2 给出测试案例
    // output is 10,9,8,7,6,5,4,3,2,1,
    printList(list);

    // 练习3
    int data = 8;
    p = ListFind(list, data);
    if (p != NULL) {
        printf("%d\n", p->customerData);
    }

    p = ListReverse(list);
    // output is 1,2,3,4,5,6,7,8,9,10,
    printList(p);

    ListFree(p);

    return 0;
}

NODE_PTR ListFind(NODE_PTR li, int i) {
    for (NODE_PTR p = li; p != NULL; p = p->next) {
        if (p->customerData == i) {
            return p;
        }
    }

    return NULL;
}

NODE_PTR ListReverse(NODE_PTR li) {
    NODE_PTR head = li;
    if (head == NULL || head->next == NULL)  // 空链或只有一个结点，直接返回头指针
    {
        return head;
    } else {
        // 一直递归，找到链表中最后一个节点
        NODE_PTR new_head = ListReverse(head->next);
        // 当逐层退出时，new_head 的指向都不变，一直指向原链表中最后一个节点；
        // 递归每退出一层，函数中 head 指针的指向都会发生改变，都指向上一个节点。
        // 每退出一层，都需要改变 head->next 节点指针域的指向，同时令 head 所指节点的指针域为 NULL。
        head->next->next = head;
        head->next = NULL;
        // 每一层递归结束，都要将新的头指针返回给上一层。由此，即可保证整个递归过程中，能够一直找得到新链表的表头。
        return new_head;
    }
}
