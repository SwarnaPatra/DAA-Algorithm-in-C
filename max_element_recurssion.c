#include <stdio.h>

int get_MAX(int A[], int n) {
    
    if (n == 1)
        return A[0];

    
    int max_of_rest = get_MAX(A, n - 1);

    
    if (A[n - 1] > max_of_rest)
        return A[n - 1];
    else
        return max_of_rest;
}

int main() {
    int A[] = {1, 5, 2, 9, 4, 3};
    int n = 6;

    int max = get_MAX(A, n);

    printf("Maximum element is: %d\n", max);

    return 0;
}
