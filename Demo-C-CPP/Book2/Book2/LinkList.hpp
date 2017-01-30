#include <stdio.h>
#include <iostream>
using namespace std;

template <typename DataType>
class ListNode;

template <typename DataType>
class LinkList {
private:
    ListNode<DataType> *head; // 头结点
    
public:
    LinkList() {
        head = new ListNode<DataType>();
    }
    
    ~LinkList() {
        delete head;
    }
    
    bool insertNode(DataType newData);
    
    bool insertNode(const int index, DataType newData);
    
    bool removeNode(ListNode<DataType> *node);
    
    ListNode<DataType>* getHeadNode();
    
    ListNode<DataType>* getNode(const int index);
    
    DataType getNodeData(const int index);
    
    ListNode<DataType>* findNode(DataType value);
    
    int getLength();
    
    void cleanLink();
    
    void print();
};

template <typename DataType>
class ListNode {
private:
    DataType data; // 结点中的数据
    ListNode<DataType> *next; // 指向下一个结点的指针
    friend class LinkList<DataType>; // 将LinkList设为友元类，方便对ListNode的成员字段和方法的方法。
    
public:
    ListNode() {
        next = NULL;
    }
    
    ListNode(DataType item, ListNode<DataType> *nextNode=NULL) {
        data = item;
        next = nextNode;
    }
    
    ~ListNode() {
        next = NULL;
    }
    
    DataType getData() {
        return data;
    }
    
    ListNode<DataType>* getNext() {
        return next;
    }
};


/**
 在表尾插入新结点

 @param newData 新结点的数据
 @return 成功返回true，失败返回false。
 */
template <typename DataType>
bool LinkList<DataType>::insertNode(DataType newData) {
    ListNode<DataType> *newNode = new ListNode<DataType>(newData);
    if (newNode == 0) {
        return false; // 新结点分配内存失败
    }
    
    ListNode<DataType> *current = head;
    while (current->next != 0) {
        current = current->next;
    }
    current->next= newNode;
    return true;
}

/**
 插入新结点到第index个位置，index从1开始计算，这里的位置指的是插入后所在的位置，如插入到第3个位
 置，则是指插入后新结点在链表中的排序是第3位。

 @param index 插入位置
 @param newData 新结点的数据
 @return 成功返回true，失败返回false。
 */
template <typename DataType>
bool LinkList<DataType>::insertNode(const int index, DataType newData) {
    if (index<1) {
        cout << "位置无效，程序结束。\n";
        exit(0);
    }
    
    ListNode<DataType> *newNode = new ListNode<DataType>(newData);
    if (newNode == 0) {
        return false; // 新结点分配内存失败
    }
    
    if (head->next == 0) { // 空链表
        cout << "链表为空，插入为第一个结点。\n";
        head->next = newNode;
        return true;
    }
    ListNode<DataType> *current = head;
    for (int i=1; i<=index-1; i++) {
        current = current->next;
        if (current->next == 0) { // 当前结点是尾结点
            cout << "位置超出链表长度，插入为最后一个结点" << endl;
            current->next = newNode;
            return true;
        }
    }
    
    newNode->next = current->next;
    current->next = newNode;
    return true;
}

/**
 删除某一个结点
 
 @param node 要删除的结点
 @return 成功返回true，失败返回false。
 */
template <typename DataType>
bool LinkList<DataType>::removeNode(ListNode<DataType> *node) {
    if (node == 0) {
        cout << "指针为空\n";
        return false;
    }
    if (head->next == 0) {
        cout << "链表为空\n";
        return false;
    }
    // 遍历链表，找到删除结点的前驱结点。
    ListNode<DataType> *current = head;
    while (current->next != 0 && current->next != node) {
        current = current->next;
    }
    if (current->next == 0) { // 已经遍历到尾结点
        cout << "结点不存在\n";
        return false;
    }
    current->next = node->next;
    delete node;
    return true;
}


/**
 获取链表的头结点

 @return 链表的头结点
 */
template <typename DataType>
ListNode<DataType>* LinkList<DataType>::getHeadNode() {
    return head;
}

/**
 获取链表第index个结点，index从1开始计算。

 @param index 结点的位置，从1开始计算。
 @return 如果结点存在，则返回结点的地址，否则，返回空指针。
 */
template <typename DataType>
ListNode<DataType>* LinkList<DataType>::getNode(const int index) {
    if (index<1) {
        cout << "位置无效，程序结束。\n";
        exit(0);
    }
    if (head->next == 0) {
        cout << "链表为空，返回空指针。\n";
        return 0;
    }
    ListNode<DataType> *current = head;
    for (int i=1; i<=index; i++) {
        current = current->next;
        if (current == 0) {
            cout << "结点不存在，返回空指针。\n";
            return 0;
        }
    }
    return current;
}

/**
 获取链表第index个结点的数据，index从1开始计算。

 @param index 结点的位置
 @return 结点的数据
 */
template <typename DataType>
DataType LinkList<DataType>::getNodeData(const int index) {
    ListNode<DataType> *node = getNode(index);
    return node->getData();
}

/**
 查找数据为value的结点

 @param value 查找数据
 @return 数据为value的结点，如果结点不存在，返回空指针。
 */
template <typename DataType>
ListNode<DataType>* LinkList<DataType>::findNode(DataType value) {
    ListNode<DataType> *p = head->next;
    while (p!=0 && p->getData()!=value) {
        p = p->next;
    }
    return p;
}

/**
 获取链表的长度

 @return 链表的长度
 */
template <typename DataType>
int LinkList<DataType>::getLength() {
    ListNode<DataType> *p = head->next;
    int count = 0;
    while (p != 0) {
        count++;
        p = p->next;
    }
    return count;
}




/**
 清空链表
 */
template <typename DataType>
void LinkList<DataType>::cleanLink() {
    ListNode<DataType> *current = head;
    while (head->next != 0) {
        current = head->next;
        head->next = current->next;
        delete current;
    }
}


/**
 打印链表的所有结点
 */
template <typename DataType>
void LinkList<DataType>::print() {
    if (head->next == 0) {
        cout << "链表为空\n";
        return;
    }
    ListNode<DataType> *p = head->next;
    while (p != 0) {
        cout << p->data << "  ";
        p = p->next;
    }
    cout << endl;
}
