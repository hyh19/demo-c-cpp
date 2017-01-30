#include <stdio.h>
#include <iostream>
using namespace std;

template <typename DataType>
class Stack {
    DataType *elements; // 存储栈的元素的数组
    int maxSize; // 栈的容量，元素个数。
    int top; // 栈顶，从0开始计算。
    
public:
    Stack(int size) {
        elements = new DataType[size];
        maxSize = size;
        top = -1;
    }
    
    ~Stack() {
        delete [] elements;
    }
    
    bool push(DataType data);
    
    DataType pop();
    
    bool isEmpty();
    
    int eleNumber();
    
    void print();
};

/**
 入栈

 @param data 元素的值
 @return 如果入栈成功，则返回true，如果入栈失败，如栈已满，则返回false。
 */
template <typename DataType>
bool Stack<DataType>::push(DataType data) {
    if (top == maxSize-1) {
        cout << "栈已满\n";
        return false;
    }
    elements[++top] = data;
    return true;
}

/**
 出栈

 @return 如果栈不为空，则返回栈顶元素，否则，程序结束。
 */
template <typename DataType>
DataType Stack<DataType>::pop() {
    if (top == -1) {
        exit(1);
    }
    return elements[top--];
}

/**
 判断一个栈是否为空栈

 @return 如果为空栈返回true，否则返回false。
 */
template <typename DataType>
bool Stack<DataType>::isEmpty() {
    return (top == -1);
}

/**
 获取栈的元素个数

 @return 栈的元素个数
 */
template <typename DataType>
int Stack<DataType>::eleNumber() {
    if (top >= 0) {
        return top+1;
    }
    return 0;
}

/**
 打印栈的元素
 */
template <typename DataType>
void Stack<DataType>::print() {
    for (int i=top; i>=0; i--) {
        cout << elements[i] << "  ";
    }
    cout << endl;
}
