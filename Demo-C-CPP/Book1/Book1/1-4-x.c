//
//  1-4-x.c
//  Demo-Data-Structure-C
//
//  Created by Yuhui Huang on 05/01/2017.
//  Copyright © 2017 Yuhui Huang. All rights reserved.
//

#include <stdio.h>
#include <math.h>

#define STACK_INIT_SIZE 20 // 初始容量
#define STACK_INCREMENT 10 // 递增容量

typedef char ElemType;


/**
 顺序栈
 */
typedef struct {
    ElemType *base; // 栈底
    ElemType *top; // 栈顶
    int stackSize; // 栈容量
} sqStack;


/**
 初始化一个栈

 @param s 要初始化的栈
 */
void initStack(sqStack *s) {
    s->base = malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if (!s->base) { exit(0); }
    s->top = s->base; // 栈顶和栈底的指针相同表示空栈
    s->stackSize = STACK_INIT_SIZE;
}


/**
 入栈

 @param s 被操作的栈
 @param e 要插入的值
 */
void push(sqStack *s, ElemType e) {
    if ((s->top - s->base) >= s->stackSize) { // 容量不够
        s->base = realloc(s->base, (s->stackSize+STACK_INCREMENT) * sizeof(ElemType));
        if (!s->base) { exit(0); }
        s->top = (s->base + s->stackSize); // 栈底的地址重新分配了，栈顶指针重新挪到顶部。
        s->stackSize += STACK_INCREMENT;
    }
    *(s->top) = e;
    ++s->top; // 栈顶指针往上挪一格
}


/**
 出栈

 @param s 被操作的栈
 @param e 出栈存放的值
 */
void pop(sqStack *s, ElemType *e) {
    if (s->top == s->base) { // 空栈
        return;
    }
    *e = *(--s->top); // 栈顶指针往下挪一格
}


/**
 栈的长度

 @param s 某一个栈
 @return 元素个数
 */
long stackLen(sqStack s) {
    return (s.top-s.base);
}

// 二进制转化为十进制
int main(int argc, const char * argv[]) {
    
    sqStack s;
    initStack(&s);
    
    printf("---- input a binary digit ----\n");
    ElemType c;
    scanf("%c", &c);
    while (c!='#') { // #表示结束输入
        push(&s, c);
        scanf("%c", &c);
    }
    printf("---- input end ----\n");
    
    long len = stackLen(s);
    int sum = 0;
    for (int i=0; i<len; ++i) {
        pop(&s, &c);
        sum += (c-'0')*pow(2,i);
    }
    printf("---- decimal is %d ----\n", sum);
    
    return 0;
}
