#include <stdio.h>
#include <stdlib.h>

#define MAX 64   // maximum allowed size

void multiply(int size, int matX[MAX][MAX], int matY[MAX][MAX], int matZ[MAX][MAX]) {
    if (size == 1) {
        matZ[0][0] = matX[0][0] * matY[0][0];
        return;
    }

    int half = size / 2;

    int p[MAX][MAX], q[MAX][MAX], r[MAX][MAX], s[MAX][MAX];
    int t[MAX][MAX], u[MAX][MAX], v[MAX][MAX], w[MAX][MAX];

    int pt[MAX][MAX], qv[MAX][MAX], pu[MAX][MAX], qw[MAX][MAX];
    int rt[MAX][MAX], sv[MAX][MAX], ru[MAX][MAX], sw[MAX][MAX];

    // Divide matrices
    for (int row = 0; row < half; row++) {
        for (int col = 0; col < half; col++) {
            p[row][col] = matX[row][col];
            q[row][col] = matX[row][col + half];
            r[row][col] = matX[row + half][col];
            s[row][col] = matX[row + half][col + half];

            t[row][col] = matY[row][col];
            u[row][col] = matY[row][col + half];
            v[row][col] = matY[row + half][col];
            w[row][col] = matY[row + half][col + half];
        }
    }

    // Recursive calls
    multiply(half, p, t, pt);
    multiply(half, q, v, qv);
    multiply(half, p, u, pu);
    multiply(half, q, w, qw);
    multiply(half, r, t, rt);
    multiply(half, s, v, sv);
    multiply(half, r, u, ru);
    multiply(half, s, w, sw);

    // Combine results
    for (int row = 0; row < half; row++) {
        for (int col = 0; col < half; col++) {
            matZ[row][col]             = pt[row][col] + qv[row][col];
            matZ[row][col + half]      = pu[row][col] + qw[row][col];
            matZ[row + half][col]      = rt[row][col] + sv[row][col];
            matZ[row + half][col + half] = ru[row][col] + sw[row][col];
        }
    }
}

void printMatrix(int size, int mat[MAX][MAX]) {
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++)
            printf("%d ", mat[r][c]);
        printf("\n");
    }
}

int main() {
    int size;
    int matX[MAX][MAX], matY[MAX][MAX], matZ[MAX][MAX] = {0};

    printf("Enter matrix size (power of 2, <= %d): ", MAX);
    scanf("%d", &size);

    printf("Enter elements of Matrix A:\n");
    for (int r = 0; r < size; r++)
        for (int c = 0; c < size; c++)
            scanf("%d", &matX[r][c]);

    printf("Enter elements of Matrix B:\n");
    for (int r = 0; r < size; r++)
        for (int c = 0; c < size; c++)
            scanf("%d", &matY[r][c]);

    multiply(size, matX, matY, matZ);

    printf("\nResultant Matrix C:\n");
    printMatrix(size, matZ);

    return 0;
}