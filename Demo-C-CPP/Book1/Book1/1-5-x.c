//
//  1-5-x.c
//  Demo-Data-Structure-C
//
//  Created by Yuhui Huang on 06/01/2017.
//  Copyright © 2017 Yuhui Huang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// 结点类型
typedef char ElemType;

/**
 队列的结点
 */
typedef struct QNode {
    ElemType data; // 数据域，存储结点的值。
    struct QNode *next; // 指针域，存储后继结点的地址。
} QNode;


/**
 链队列
 */
typedef struct {
    QNode *front; // 头结点指针，指针域存储第一个结点的地址。
    QNode *rear; // 尾结点指针，指向最后一个结点。
} LinkedQueue;


/**
 初始化队列

 @param q 操作队列
 */
void initQueue(LinkedQueue *q) {
    // 创建一个空队列
    q->front = q->rear = malloc(sizeof(QNode));
    if (!q->front) {
        exit(0);
    }
    q->front->next = NULL;
}


/**
 入列

 @param q 操作队列
 @param e 入列结点的值
 */
void enqueue(LinkedQueue *q, ElemType e) {
    QNode *newNode = malloc(sizeof(QNode));
    if (!newNode) { // 创建新结点失败
        exit(0);
    }
    newNode->data = e;
    newNode->next = NULL;
    q->rear->next = newNode; // 新入列的结点调整为最后一个结点
    q->rear = newNode; // 尾结点指针重新指向最后一个结点
}


/**
 出列

 @param q 操作队列
 @param e 出列结点的值
 */
void dequeue(LinkedQueue *q, ElemType *e) {
    if (q->front == q->rear) { // 空队列
        return;
    }
    QNode *firstNode = q->front->next; // 第一个结点出列
    *e = firstNode->data;
    q->front->next = firstNode->next; // 第二个结点调整为第一个结点
    if (q->rear == firstNode) { // 如果队列只有一个结点，则出列后成为空队列。
        q->rear = q->front;
    }
    free(firstNode);
}


/**
 打印队列的结点

 @param q 操作队列
 */
void printQueue(LinkedQueue q) {
    printf("---- print begin ----\n");
    ElemType e;
    while (q.front != q.rear) {
        dequeue(&q, &e); // 从第一个结点开始，从头到尾打印。
        printf("%c ", e);
    }
    printf("\n---- print end ----\n");
}

int main(int argc, const char * argv[]) {
    LinkedQueue queue;
    initQueue(&queue);
    
    printf("---- input a string ----\n");
    ElemType e;
    scanf("%c", &e);
    while (e != '#') {
        enqueue(&queue, e);
        scanf("%c", &e);
    }
    printf("---- end input ----\n");
    
    printQueue(queue);
    
    return 0;
}
