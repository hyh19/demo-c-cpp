//
//  2-6-x.c
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
 希尔排序，从小到大排序整数。
 
 @param a 数组
 @param n 数组的元素个数
 */
void shellSort(int a[], int n) {
    int gap = n;
    int flag;;
    while (gap > 1) {
        gap = gap/2; // 元素间隔（跨度）每次减半
        do {
            flag = 0;
            for (int i=0; i<n-gap; i++) {
                if (a[i] > a[i+gap]) {
                    swap(&a[i], &a[i+gap]);
                    flag = 1;
                }
            }
        } while (flag==1);/**
                           希尔排序属于不稳定排序，冒泡排序过程中会出现已有排序被破坏的情
                           况，所以，只要排序过程中出现过元素的交换，都要再次进行冒泡排序
                           进行元素的重排，直到排序稳定为止。
                           
                           17, 2, 23, 14, 11, 7, 5, 9
                           例如，上面的序列是数组经历了gap=4的排序后的，接下来的gap=2的
                           排序，17和23比较后不需要交换，但是23和11比较后需要交换，这次
                           交换破坏了前面的排序，所以，交换后17和11要再进行一次比较。
                           */
        
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
    
    shellSort(a, n);
    printArray(a, n);
    
    return 0;
}
