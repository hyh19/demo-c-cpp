#include <stdio.h>
#include <iostream>
using namespace std;

template <typename DataType>
class Queue {
    int count;
    int maxSize;
    int front;
    int rear;
    DataType *elements;
    
public:
    Queue(int size) {
        maxSize = size;
        front = 0;
        rear = 0;
        count = 0;
        elements = new DataType[size];
        if (elements == nullptr) {
            exit(1);
        }
    }
    
    ~Queue() {
        delete [] elements;
    }
    
    bool enqueue(DataType data);
    
    DataType dequeue();
    
    int getLength();
    
    void print();
};

template <typename DataType>
bool Queue<DataType>::enqueue(DataType data) {
    if (count == maxSize) {
        cout << "队列已满\n";
        return false;
    }
    elements[rear] = data;
    // 为节省空间，front和rear超出数组最大容量的时候，会回到0开始重新计算，所以用求余的方式。
    rear = (rear+1) % maxSize;
    count++;
    return true;
}

template <typename DataType>
DataType Queue<DataType>::dequeue() {
    if (count == 0) {
        cout << "队列为空，程序结束。\n";
        exit(1);
    }
    DataType e = elements[front];
    // 为节省空间，front和rear超出数组最大容量的时候，会回到0开始重新计算，所以用求余的方式。
    front = (front+1) % maxSize;
    count--;
    return e;
}

/**
 获取队列的长度

 @return 队列的元素个数
 */
template <typename DataType>
int Queue<DataType>::getLength() {
    return count;
}

/**
 打印队列的全部元素
 */
template <typename DataType>
void Queue<DataType>::print() {
    if (count == 0) {
        cout << "队列为空\n";
        return;
    }
    for (int i=front; i<front+count; i++) {
        // 为节省空间，front和rear超出数组最大容量的时候，会回到0开始重新计算，所以用求余的方式。
        cout << elements[i%maxSize] << "  ";
    }
    cout << endl;
}
