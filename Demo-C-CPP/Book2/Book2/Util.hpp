#include <stdio.h>
#include <iostream>
using namespace std;

/**
 交换两个变量的值

 @param a 变量a
 @param b 变量b
 */
template <typename T>
void swap(T *a, T *b) {
    T temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


/**
 打印数组的元素

 @param a 数组
 @param n 数组的元素个数
 */
template <typename T>
void printArray(T a[], int n) {
    cout << "---- print Array begin ----\n";
    for (int i=0; i<n; i++) {
        cout << a[i] << "  ";
    }
    cout << "\n---- print Array end ----\n";
}
