#include <stdio.h>

// 打印数组的元素
void printArray(int a[], int n) {
    printf("---- print array begin ----\n");
    for (int i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n---- print array end ----\n");
}

// 交换两个整数的顺序
void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
