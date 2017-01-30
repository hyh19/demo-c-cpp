//
//  2-2-x.c
//  Demo-Data-Structure-C
//
//  Created by Yuhui Huang on 08/01/2017.
//  Copyright © 2017 Yuhui Huang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


/**
 二分查找算法

 @param A 有序序列
 @param n 有序序列的元素个数
 @param key 要查找的元素
 @return 查找出来的索引
 */
int binSearch(int A[], int n, int key) {
    int low = 0;
    int high = n-1;
    int mid;
    while (low<=high) {
        mid = (low+high)/2;
        if (A[mid] == key) { // 查找成功
            return mid;
        }
        if (A[mid] < key) { // 在后半序列中查找
            low = mid+1;
        }
        if (A[mid] > key) { // 在前半序列中查找
            high = mid-1;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    
    int A[10] = {2, 3, 5, 7, 8, 10, 12, 15, 19, 21};
    printf("The contents of the Array A[10] are\n");
    for (int i=0; i<10; ++i) {
        printf("%d ", A[i]);
    }
    int index = binSearch(A, 10, 8);
    printf("\nindex: %d\n", index);
    
    return 0;
}
