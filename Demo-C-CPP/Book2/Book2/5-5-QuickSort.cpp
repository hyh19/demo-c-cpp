#include <stdio.h>
#include <iostream>
#include "Util.hpp"
using namespace std;

/**
 快速排序，从小到大排序。
 
 @param a 数组
 @param start 数组的起始索引
 @param end 数组的结束索引
 */
template <typename T>
void quickSort(T a[], int start, int end) {
    if (start >= end) {
        return;
    }
    int i = start; // i表示从左边开始的游标
    int j = end+1; // j表示从右边开始的游标，数组（或子数组）最后一个元素的下一位置。
    // 选择第一个元素作为划界元素
    T *base = &(a[start]);
    while (1) {
        do {
            i++; // 从左边开始找到比划界元素大的为止
        } while (a[i] <= *base && i<end);
        
        do {
            j--; // 从右边开始找到比划界元素小的为止
        } while (a[j] >= *base && j>start);
        
        if (i<j) {
            swap(&a[i], &a[j]);
        } else {
            break; // 左右两个游标相遇，本轮分组排序结束。
        }
    }
    swap(base, &a[j]); // 划界元素换到其最终位置
    /**
     递归排序左子序列和右子序列
     */
    quickSort(a, start, j-1);
    quickSort(a, j+1, end);
}

int main() {
    int a[] = {3, 12, 8, 14, 2, 5, -3, 23, 16};
    int n = sizeof(a)/sizeof(int);
    printArray(a, n);
    
    cout << "\n---- Quick Sort ----\n\n";
    
    quickSort(a, 0, n);
    printArray(a, n);
    return 0;
}
