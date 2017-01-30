#include <stdio.h>
#include <iostream>
#include "Util.hpp"
using namespace std;

/**
 冒泡排序，从小到大。

 @param a 数组
 @param n 数组的元素个数
 */
template <typename T>
void bubbleSort(T a[], int n) {
    int flag = 1; // 某一趟比较是否发生过前后元素交换，1表示有发生，0表示没有发生。
    // i表示第几趟排序，总共需要进行n-1趟两两比较。
    for (int i=1; i<=n-1 && flag==1; i++) {
        flag = 0;
        for (int j=0; j<=n-1-i; j++) {
            if (a[j]>a[j+1]) {
                swap(&a[j], &a[j+1]);
                flag = 1;
            }
        }
    }
}

int main() {
    int a[] = {3, 12, 8, 14, 2, 5, -3, 23, 16};
    int n = sizeof(a)/sizeof(int);
    printArray(a, n);
    
    cout << "\n---- Bubble Sort ----\n\n";
    
    bubbleSort(a, n);
    printArray(a, n);
}
