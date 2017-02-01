#include <stdio.h>
#include <stdlib.h>

typedef int ElemType; // 元素类型为整型

/**
 链表结点
 */
typedef struct Node {
    ElemType data; // 结点的数据
    struct Node *next; // 后继结点
} Node, *LinkedList; // 链表，头结点的后继才是第一个结点。

/**
 创建链表
 
 @return 新创建的链表
 */
LinkedList createList() {
    LinkedList header = malloc(sizeof(Node)); // 创建头结点
    if (header == NULL) {
        exit(1);
    }
    return header;
}

/**
 初始化链表

 @param list 要初始化的链表
 */
void initList(LinkedList *list) {
    *list = malloc(sizeof(Node)); // 创建头结点
    if (*list == NULL) {
        exit(1); // 分配内存失败
    }
}

/**
 插入一个新结点到链表中某一个结点的后面

 @param list 要插入的链表
 @param pos 在该结点后插入，允许插入到头结点后面作为第一个结点。
 @param e 新结点的数据
 @return 新结点的地址
 */
Node* insert(LinkedList *list, Node *pos, ElemType e) {
    Node *newNode = malloc(sizeof(Node)); // 分配内存给新结点
    if (newNode == NULL) {
        exit(1); // 分配内存失败
    }
    newNode->data = e;
    newNode->next = pos->next;
    pos->next = newNode;
    return newNode;
}

/**
 删除链表中的某一个结点

 @param list 要删除的链表
 @param pos 要删除的结点
 */
void delete(LinkedList *list, Node *pos) {
    Node *current = *list;
    while (current && current->next != pos) {
        current = current->next;
    }
    current->next = pos->next;
    free(pos);
}

/**
 查找数据为e的结点
 
 @param list 要查找的链表
 @param e 要查找的数据
 @return 查找到的结点，如果为NULL，表示没有找到。
 */
Node* find(LinkedList list, ElemType e) {
    Node *current = list->next; // 初始化为第一个结点
    while (current && current->data != e) {
        current = current->next;
    }
    return current;
}

/**
 销毁链表

 @param list 要销毁的链表
 */
void destroyList(LinkedList *list) {
    Node *current = NULL; // 游标
    Node *delNode = (*list); // 存放要删除的结点
    while (delNode) {
        current = delNode->next;
        free(delNode);
        delNode = current;
    }
    *list = NULL;
}

/**
 打印链表

 @param list 要打印的链表
 */
void printList(LinkedList list) {
    printf("---- print list begin ----\n");
    Node *current = list->next;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n---- print list end ----\n");
}

int main() {
    LinkedList list = NULL;
    initList(&list);
    printList(list);
    
    Node *pos = list;
    for (int i=1; i<=10; i++) {
        pos = insert(&list, pos, i*10);
    }
    printList(list);
    
    Node* result = find(list, 50);
    delete(&list, result);
    printList(list);
    
    destroyList(&list);
    return 0;
}
