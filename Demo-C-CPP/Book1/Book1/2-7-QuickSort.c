#include <stdio.h>

/**
 交换两个整数的顺序
 
 @param a 整数a
 @param b 整数b
 */
void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


/**
 快速排序，从小到大排序整数。

 @param a 数组
 @param start 数组的起始索引
 @param end 数组的结束索引
 */
void quickSort(int a[], int start, int end) {
    if (start >= end) {
        return;
    }
    int i = start; // i表示从左边开始的游标
    int j = end+1; // j表示从右边开始的游标，数组（或子数组）最后一个元素的下一位置。
    // 选择第一个元素作为划界元素
    int *base = &(a[start]);
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

void printArray(int a[], int n) {
    printf("---- print begin ----\n");
    for (int i=0; i<n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n---- print end ----\n");
}

int main(int argc, const char * argv[]) {
    
    int a[] = {-111, 110, 5, 29, 3, 7, 8, 0, 9, 12, 1, 30};
    int n =  sizeof(a)/sizeof(a[0]);
    printArray(a, n);
    printf("\n---- after sort ----\n\n");
    quickSort(a, 0, n-1);
    printArray(a, n);
    
    return 0;
}
