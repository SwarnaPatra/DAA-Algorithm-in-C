#include <stdio.h>

#define MAX 64   


void walsh(int W[MAX][MAX], int n) {
    
    if (n == 1) {
        W[0][0] = 1;
        return;
    }

    
    walsh(W, n / 2);

    
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            W[i][j + n / 2] = W[i][j];              
            W[i + n / 2][j] = W[i][j];              
            W[i + n / 2][j + n / 2] = -W[i][j];     
        }
    }
}

int main() {
    int N;
    int W[MAX][MAX];

    printf("Enter order of Walsh matrix (power of 2): ");
    scanf("%d", &N);

    walsh(W, N);

    printf("Walsh Matrix of order %d:\n", N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%3d ", W[i][j]);
        }
        printf("\n");
    }

    return 0;
}