#include <stdio.h>
#include <stdlib.h>
#include "struct_demo.h"

// #include ""引入自己编写的头文件
// #include <>引入系统的头文件

// #define 预定义

// typedef 类型定义

#define ERROR 0
#define OK 1
typedef int Status;

typedef struct {
    int data;
} ElemType;

typedef struct LNode {
    ElemType *elemType;
    struct LNode *next;
} LNode, *LinkList;

Status GetElem_L(LinkList L, int i, ElemType *e);

Status ListInsert_L(LinkList L, int i, ElemType *e);

Status ListDelete_L(LinkList L, int i, ElemType *e);

void CreateList_L(int n);

Status traverse_L(LinkList L);

void MergeList(LinkList LA, LinkList LB);

void testMergeList() {
    ElemType a1 = {1};
    ElemType a2 = {2};
    ElemType a3 = {4};
    ElemType a4 = {6};
    ElemType a5 = {8};

    LNode l5 = {&a5, 0};
    LNode l4 = {&a4, &l5};
    LNode l3 = {&a3, &l4};
    LNode l2 = {&a2, &l3};
    LNode l1 = {&a1, &l2};
    LNode lahead = {0, &l1};

    LinkList LA = &lahead;

    traverse_L(LA);


    ElemType b3 = {10};
    ElemType b2 = {5};
    ElemType b1 = {3};

    LNode lb3 = {&b3, 0};
    LNode lb2 = {&b2, &lb3};
    LNode lb1 = {&b1, &lb2};
    LNode lbhead = {0, &lb1};

    LinkList LB = &lbhead;
    traverse_L(LB);

    MergeList(LA, LB);

}

int main() {

    /*LinkList head;

    ElemType e5 = {5};
    LNode l5 = {&e5, 0};

    ElemType e4 = {4};
    LNode l4 = {&e4, &l5};

    ElemType e3 = {3};
    LNode l3 = {&e3, &l4};

    ElemType e2 = {2};
    LNode l2 = {&e2, &l3};

    ElemType e1 = {1};
    LNode l1 = {&e1, &l2};

    head = &l1;

    ElemType insertItem = {9};
    ListInsert_L(head, 3, &insertItem);

    ElemType *deleteItem = malloc(sizeof(ElemType *));
    ListDelete_L(head, 3, deleteItem);

    CreateList_L(5);*/

    testMergeList();

    return 0;
}

// 从链表中查找第i个元素项
Status GetElem_L(LinkList L, int i, ElemType *e) {
    int j = 1;
    while (L && j < i) {
        L = (LinkList) L->next;
        j++;
    }
    if (!L || j > i) {
        return ERROR;
    }
    e = L->elemType;
    printf("e : %d", e->data);
    return OK;
}

// 在链表的i个元素之前插入数据项e
Status ListInsert_L(LinkList L, int i, ElemType *e) {

    printf("before insert>>>\n");
    traverse_L(L);

    LinkList p = L;
    int j = 1;
    while (p && j < i - 1) {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1) {
        return ERROR;
    }
    // printf("NO %d is %d", i - 1, L->elemType->data);

    LinkList s = (LinkList) malloc(sizeof(LNode));
    s->elemType = e;
    s->next = p->next;
    p->next = s;

    printf("after insert>>>\n");
    traverse_L(L);

    return OK;
}

// 删除第i个元素
Status ListDelete_L(LinkList L, int i, ElemType *e) {

    printf("before delete>>>\n");
    traverse_L(L);

    LinkList p = L;
    if (i == 1) {
        L = p->next;
        printf("after delete>>>\n");
        traverse_L(L);
        return OK;
    }
    int j = 1;
    while (p && j < i - 1) {
        j++;
        p = p->next;
    }
    if (!p || j > i - 1) {
        return ERROR;
    }

    LinkList d = p->next;
    p->next = d->next;
    e = d->elemType;
    // free(d);

    printf("after delete>>>\n");
    traverse_L(L);

    return OK;
}

// 遍历链表
Status traverse_L(LinkList L) {
    if (!L) {
        return ERROR;
    }
    printf("\n");
    LinkList p = L->next;
    int i = 1;
    while (p) {
        if (p->elemType->data) {
            if (p->next) {
                printf("%d->", p->elemType->data);
            } else {
                printf("%d", p->elemType->data);
            }
        }
        p = p->next;
        i++;
    }
    return OK;
}

void CreateList_L(int n) {
    LinkList L = (LinkList) malloc(sizeof(LNode));
    L->next = NULL;
    for (int i = n; i > 0; i--) {
        LinkList p = (LinkList) malloc(sizeof(LNode));
        ElemType *e = malloc(sizeof(ElemType *));
        p->elemType = e;
        scanf("%d", &e->data);
        p->next = L->next;
        L->next = p;
    }

    L = L->next;

    traverse_L(L);
}

void MergeList(LinkList LA, LinkList LB) {
    LinkList pa = LA->next;
    LinkList pb = LB->next;
    LinkList LC = LA;
    LinkList pc = LA;
    while (pa && pb) {
        if (pa->elemType->data <= pb->elemType->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }

    pc->next = pa ? pa : pb;
    traverse_L(LC);
}