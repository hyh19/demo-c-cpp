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

// 冒泡排序，从小到到排序整数。
void bubbleSort(int a[], int n) {
    int flag = 1; // 某一趟比较是否发生过前后元素交换，1表示有发生，0表示没有发生。
    // 进行n-1趟两两比较
    for (int t=1; t<=n-1 && flag==1; t++) {
        flag = 0;
        for (int j=0; j<=n-1-t; j++) {
            if (a[j]>a[j+1]) {
                swap(&a[j], &a[j+1]);
                flag = 1;
            }
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
    
    bubbleSort(a, n);
    printArray(a, n);
    
    return 0;
}
