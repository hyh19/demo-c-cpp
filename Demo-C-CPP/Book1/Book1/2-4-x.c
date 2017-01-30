//
//  2-4-x.c
//  Demo-Data-Structure-C
//
//  Created by Yuhui Huang on 10/01/2017.
//  Copyright © 2017 Yuhui Huang. All rights reserved.
//

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
 选择排序算法

 @param a 数组
 @param n 数组元素的个数
 */
void selectSort(int a[], int n) {
    int i, j, min;
    for (i=0; i<n-1; ++i) {
        min = i;
        for (j=i+1; j<n; ++j) {
            if (a[j]<a[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(&a[min], &a[i]);
        }
    }
}

void printArray(int a[], int n) {
    printf("---- print begin ----\n");
    for (int i=0; i<n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n---- print end ----\n");
}

int main(int argc, const char * argv[]) {
    
    int a[] = {-111, 2, 5, 6, 3, 7, 8, 0, 9, 12, 1};
    int n =  sizeof(a)/sizeof(a[0]);
    printArray(a, n);
    
    selectSort(a, n);
    printArray(a, n);
    
    return 0;
}
