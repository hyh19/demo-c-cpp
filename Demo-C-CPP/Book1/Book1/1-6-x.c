//
//  1-6-x.c
//  Demo-Data-Structure-C
//
//  Created by Yuhui Huang on 07/01/2017.
//  Copyright © 2017 Yuhui Huang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;


/**
 用先序遍历方式创建二叉树

 @param T 二叉树
 */
void createBiTreeWithPreOrder(BiTree *T) {
    char c;
    scanf("%c", &c);
    if (c == '#') { // 用#表示结点为空，如A##表示根结点A的左右子结点都为空。
        *T = NULL;
    } else {
        *T = malloc(sizeof(BiTNode));
        (*T)->data = c;
        // 递归创建左右子树
        createBiTreeWithPreOrder(&( (*T)->lchild ));
        createBiTreeWithPreOrder(&( (*T)->rchild ));
    }
}

/**
 访问二叉树某个结点的值

 @param c 结点的值
 @param level 结点所在的层数
 */
void visit(char c, int level) {
    if (c == 'D') {
        printf("%c is at %d level of BiTree\n", c, level);
    }
}


/**
 先序遍历二叉树

 @param T 二叉树
 @param level 二叉树的层数
 */
void preOrderTraverse(BiTree T, int level) {
    if (T) {
        visit(T->data, level);
        preOrderTraverse(T->lchild, level+1);
        preOrderTraverse(T->rchild, level+1);
    }
}

// 用先序序列创建一棵二叉树，并输出字符D位于二叉树的层数。
int main(int argc, const char * argv[]) {
    
    BiTree T = NULL;
    createBiTreeWithPreOrder(&T);
    int level = 1;
    preOrderTraverse(T, level);
    
    return 0;
}
