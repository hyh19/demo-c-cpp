//
//  1-3-x.c
//  Demo-Data-Structure-C
//
//  Created by Yuhui Huang on 03/01/2017.
//  Copyright © 2017 Yuhui Huang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct node {
    ElemType data;
    struct node *next;
} LNode, *LinkList;


/**
 创建一个有n个结点的链表，每个结点的值默认为序号。

 @param n 结点的个数
 @return 指向链表的指针，也就是头结点的地址。
 */
LinkList createLinkList(int n) {
    LinkList list = NULL;
    LNode *newNode = NULL; // 指向新创建的结点的指针
    LNode *lastNode = NULL; // 指向最后一个结点的指针
    for (int i=1; i<=n; ++i) {
        newNode = malloc(sizeof(LNode));
        newNode->data = i;
        newNode->next = NULL;
        if (!list) {
            list = newNode; // 头结点，用于标记链表。
        } else {
            lastNode->next = newNode;
        }
        lastNode = newNode;
    }
    return list;
}


/**
 插入一个新结点到链表中某一个结点的后面

 @param list 需要插入的链表
 @param posNode 在该位置后插入
 @param e 要插入的结点的值
 */
void insertElem(LinkList *list, LNode *posNode, ElemType e) {
    LNode *insertNode = malloc(sizeof(LNode)); // 要插入的结点
    insertNode->data = e;
    if (!(*list)) {
        *list = insertNode;
        insertNode->next = NULL;
    } else {
        insertNode->next = posNode->next;
        posNode->next = insertNode;
    }
}

/**
 删除链表中的某一个结点

 @param list 要删除的链表
 @param delNode 要删除的结点
 */
void deleteElem(LinkList *list, LNode *delNode) {
    if (delNode == (*list)) { // 删除头结点
        *list = delNode->next;
        free(delNode);
    } else {
        LNode *cur = NULL;
        for (cur=(*list); cur->next!=delNode; cur=cur->next) {
            // 遍历链表，找到要删除的结点的前驱结点。
        }
        if (cur) {
            cur->next = delNode->next;
            free(delNode);
        }
    }
}


/**
 销毁链表

 @param list 要销毁的链表
 */
void destroyLinkList(LinkList *list) {
    LNode *delNode = NULL; // 存放要删除的结点
    LNode *cur = NULL; // 游标
    delNode = *list;
    while (delNode) {
        cur = delNode->next;
        free(delNode);
        delNode = cur;
    }
    *list = NULL;
}


/**
 打印链表

 @param list 需要打印的链表
 */
void printLinkList(LinkList list) {
    if (!list) {
        printf("---- empty list ---- \n\n");
        return;
    }
    LNode *cur = list;
    printf("---- print begin ----\n");
    while (cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n---- print end ----\n\n");
}

int main(int argc, const char * argv[]) {
    
    LinkList list = createLinkList(10);
    printLinkList(list);
    
    // 在第一个结点后插入一个值
    LNode *posNode = list;
    insertElem(&list, posNode, 234);
    printLinkList(list);
    
    // 删除第五个结点
    LNode *delNode = list;
    for (int i=0; i<4; ++i) {
        delNode = delNode->next;
    }
    deleteElem(&list, delNode);
    printLinkList(list);
    
    destroyLinkList(&list);
    printLinkList(list);
    
    return 0;
}
