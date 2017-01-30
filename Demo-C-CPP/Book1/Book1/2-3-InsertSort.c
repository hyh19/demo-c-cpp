#include <stdio.h>
#include <stdlib.h>

/**
 直接插入排序，从小到大排序整数。

 @param a 数组
 @param n 数组的元素个数
 */
void insertSort(int a[], int n) {
    /**
     { (a[0], a[1], a[2]...a[i-1]), a[i], a[i+1]...a[n-1] }
     - a[0]至a[i-1]表示已经排序过的子序列
     - 从a[i]开始一直到a[n-1]每一个都要选择插入到前面已经排序过的子序列的相应位置，形成一个新的
     有序子序列，并循环重复这一个步骤。
     */
    for (int i=1; i<=n-1; ++i) { // 从第二个元素开始
        if (a[i] < a[i-1]) { // 如果a[i]>=a[i-1]，则表示a[i]比排序过的子序列所有元素都大，直接插入到子序列的末尾。
            int key = a[i]; // 待排序的元素
            int j;
            /**
             从后往前遍历子序列(a[0], a[1], a[2]...a[i-1])，直到找到比a[i]小的元素为
             止，如果a[j]<=key，则插入到它的后面，也就是key赋值给a[j+1]。
             */
            for (j=i-1; j>=0 && a[j]>key; j--) {
                a[j+1] = a[j]; // 比key大的元素都往后移动一个位置，腾出一个位置插入元素key。
            }
            a[j+1] = key;
        }
    }
}

// 打印数组的元素
void printArray(int a[], int n) {
    printf("---- print begin ----\n");
    for (int i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n---- print end ----\n");
}

int main(int argc, const char * argv[]) {
    int a[] = {-111, 2, 5, 6, 3, 7, 8, 0, 9, 12, 1};
    int n =  sizeof(a)/sizeof(a[0]);
    printArray(a, n);
    printf("\n---- after sort ----\n\n");
    insertSort(a, n);
    printArray(a, n);
    return 0;
}
