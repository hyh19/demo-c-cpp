#include <stdio.h>
#include <iostream>
#include "Util.hpp"
using namespace std;

/**
 选择排序，从小到大排序。

 @param a 数组
 @param n 数组的元素个数
 */
template <typename T>
void selectionSort(T a[], int n) {
    int max;
    for (int i=1; i<n; i++) { // i表示第几趟排序
        max = n-i; // max初始化为序列 (a[0], a[1]...a[n-i]) 的最后一个位置
        for (int j=0; j<n-i+1; j++) {
            if (a[j] > a[max]) { // 找出序列 (a[0], a[1]...a[n-i]) 最大的一个元素，并记录下位置。
                max = j;
            }
        }
        if (max != n-i) {
            swap(&a[max], &a[n-i]); // 将最大的元素放到序列 (a[0], a[1]...a[n-i]) 的最后一个位置
        }
    }
}

int main() {
    char a[] = {'E', 'X', 'A', 'S', 'i', 'L', 'E'};
    int n = sizeof(a)/sizeof(a[0]);
    printArray(a, n);
    
    cout << "\n---- Selection Sort ----\n\n";
    selectionSort(a, n);
    printArray(a, n);
    return 0;
}
