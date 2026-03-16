#include <stdio.h>

#define MAX 10


int det(int A[MAX][MAX], int n) {
    int determinant = 0;
    int temp[MAX][MAX];

    
    if (n == 1)
        return A[0][0];

    
    if (n == 2)
        return (A[0][0] * A[1][1] - A[0][1] * A[1][0]);

    
    for (int col = 0; col < n; col++) {
        int subi = 0;

        
        for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == col)
                    continue;
                temp[subi][subj] = A[i][j];
                subj++;
            }
            subi++;
        }

        int sign = (col % 2 == 0) ? 1 : -1;
        determinant += sign * A[0][col] * det(temp, n - 1);
    }

    return determinant;
}

int main() {
    int A[MAX][MAX], n;

    printf("Enter order of matrix (n): ");
    scanf("%d", &n);

    printf("Enter elements of %d x %d matrix:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    int result = det(A, n);

    printf("Determinant of the matrix is: %d\n", result);

    return 0;
}