#include <stdio.h>
#include <iostream>
#include "Util.hpp"
using namespace std;

/**
 直接插入排序，从小到大排序。
 
 @param a 数组
 @param n 数组的元素个数
 */
template <typename T>
void insertSort(T a[], int n) {
    /**
     { (a[0], a[1], a[2]...a[i-1]), a[i], a[i+1]...a[n-1] }
     - a[0]至a[i-1]表示已经排序过的子序列
     - 从a[i]开始一直到a[n-1]每一个都要选择插入到前面已经排序过的子序列的相应位置，形成一个新的
     有序子序列，并循环重复这一个步骤。
     */
    for (int i=1; i<=n-1; ++i) { // i表示数组元素的索引，从第二个元素开始。
        if (a[i] < a[i-1]) { // 如果a[i]>=a[i-1]，则表示a[i]比排序过的子序列所有元素都大，直接插入到子序列的末尾。
            T base = a[i]; // 待排序的元素
            int j;
            /**
             从后往前遍历子序列(a[0], a[1], a[2]...a[i-1])，直到找到比a[i]小的元素为
             止，如果a[j]<=key，则插入到它的后面，也就是key赋值给a[j+1]。
             */
            for (j=i-1; j>=0 && a[j]>base; j--) {
                a[j+1] = a[j]; // 比key大的元素都往后移动一个位置，腾出一个位置插入元素key。
            }
            a[j+1] = base;
        }
    }
}

int main() {
    int a[] = {3, 12, 8, 14, 2, 5, -3};
    int n = sizeof(a)/sizeof(int);
    printArray(a, n);
    
    cout << "\n---- Insert Sort ----\n\n";
    
    insertSort(a, n);
    printArray(a, n);
}
