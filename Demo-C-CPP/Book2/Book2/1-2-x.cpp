#include <stdio.h>
#include "LinkList.hpp"


/**
 获取链表倒数第m个结点，m从1开始计算。

 @param list 链表
 @param m 倒数位置
 @return 如果结点存在，则返回结点地址，否则，返回空指针。
 */
ListNode<int>* searchNodeM(LinkList<int> *list, const int m) {
    if (m < 1) {
        cout << "位置无效，程序结束。\n";
        exit(0);
    }
    ListNode<int> *current = list->getNode(1);
    if (current == 0) { // 链表为空
        cout << "链表为空\n";
        return 0;
    }
    // 先遍历到第m个结点
    for (int i=1; i<=m-1; i++) {
        current = current->getNext();
        if (current == 0) {
            cout << "该链表没有倒数第m个结点\n";
            return 0;
        }
    }
    // 倒数结点
    ListNode<int> *mNode = list->getNode(1);
    while (current->getNext() != 0) {
        current = current->getNext();
        mNode = mNode->getNext();
    }
    return mNode;
}

int main() {
    LinkList<int> *list = new LinkList<int>();
    for (int i=1; i<=10; i++) {
        list->insertNode(i*100);
    }
    list->print();
    
    ListNode<int> *node = searchNodeM(list, 2);
    cout << node->getData() << endl;
    return 0;
}
