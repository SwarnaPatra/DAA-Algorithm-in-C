#include <stdio.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void permutations(int A[], int start, int n) {
    
    if (start == n - 1) {
        for (int i = 0; i < n; i++)
            printf("%d ", A[i]);
        printf("\n");
        return;
    }

    
    for (int i = start; i < n; i++) {
        swap(&A[start], &A[i]);          
        permutations(A, start + 1, n);   
        swap(&A[start], &A[i]);          
    }
}

int main() {
    int A[] = {1, 2, 3};
    int n = 3;

    printf("All permutations are:\n");
    permutations(A, 0, n);

    return 0;
}

