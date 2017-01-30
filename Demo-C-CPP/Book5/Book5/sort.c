#include <stdio.h>
#include "Util.h"

typedef int ElementType;

void ShellSort(ElementType A[], int N) {
    int i, j, Increment;
    ElementType Tmp;
    for (Increment=N/2; Increment>0; Increment/=2) {
        for (i=Increment; i<N; i++) {
            Tmp = A[i];
            for (j=i; j>=Increment; j-=Increment) {
                if (Tmp<A[j-Increment]) {
                    A[j] = A[j-Increment];
                } else {
                    break;
                }
            }
            A[j] = Tmp;
        }
    }
}

int main() {
    int a[] = {-111, 2, 5, 6, 23, 7, 8, 0, 9, 12, 1};
    int n =  sizeof(a)/sizeof(a[0]);
    printArray(a, n);
    printf("\n---- shell sort ----\n\n");
    ShellSort(a, n);
    printArray(a, n);
    return 0;
}
