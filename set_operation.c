#include <stdio.h>
#include <math.h>

#define MAX 20

int isSet(char set[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (set[i] == set[j])
                return 0;
    return 1;
}


int isMember(char x, char set[], int n) {
    for (int i = 0; i < n; i++)
        if (set[i] == x)
            return 1;
    return 0;
}


void unionSet(char A[], int nA, char B[], int nB) {
    char U[MAX];
    int k = 0;

    for (int i = 0; i < nA; i++)
        U[k++] = A[i];

    for (int i = 0; i < nB; i++)
        if (!isMember(B[i], A, nA))
            U[k++] = B[i];

    printf("Union: { ");
    for (int i = 0; i < k; i++)
        printf("%c ", U[i]);
    printf("}\n");
}


void intersectionSet(char A[], int nA, char B[], int nB) {
    printf("Intersection: { ");
    for (int i = 0; i < nA; i++)
        if (isMember(A[i], B, nB))
            printf("%c ", A[i]);
    printf("}\n");
}


void differenceSet(char A[], int nA, char B[], int nB) {
    printf("A - B: { ");
    for (int i = 0; i < nA; i++)
        if (!isMember(A[i], B, nB))
            printf("%c ", A[i]);
    printf("}\n");
}


int isSubset(char A[], int nA, char B[], int nB) {
    for (int i = 0; i < nA; i++)
        if (!isMember(A[i], B, nB))
            return 0;
    return 1;
}


void cartesianProduct(char A[], int nA, char B[], int nB) {
    printf("A x B: { ");
    for (int i = 0; i < nA; i++)
        for (int j = 0; j < nB; j++)
            printf("(%c,%c) ", A[i], B[j]);
    printf("}\n");
}


void powerSet(char A[], int n) {
    int pSize = pow(2, n);
    printf("Power Set P(A):\n");

    for (int i = 0; i < pSize; i++) {
        printf("{ ");
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                printf("%c ", A[j]);
        printf("}\n");
    }
}

int main() {
    char A[MAX], B[MAX], U[MAX];
    int nA, nB, nU;
    char x;

    printf("Enter number of elements in A: ");
    scanf("%d", &nA);
    printf("Enter elements of A: ");
    for (int i = 0; i < nA; i++)
        scanf(" %c", &A[i]);

    printf("Enter number of elements in B: ");
    scanf("%d", &nB);
    printf("Enter elements of B: ");
    for (int i = 0; i < nB; i++)
        scanf(" %c", &B[i]);

    printf("Enter number of elements in Universal Set U: ");
    scanf("%d", &nU);
    printf("Enter elements of U: ");
    for (int i = 0; i < nU; i++)
        scanf(" %c", &U[i]);

    
    if (isSet(A, nA))
        printf("A is a valid set\n");
    else
        printf("A is NOT a valid set\n");


    printf("Cardinality of A: %d\n", nA);

    
    printf("Enter element to check membership in A: ");
    scanf(" %c", &x);
    if (isMember(x, A, nA))
        printf("%c belongs to A\n", x);
    else
        printf("%c does not belong to A\n", x);

    
    printf("Complement of A: { ");
    for (int i = 0; i < nU; i++)
        if (!isMember(U[i], A, nA))
            printf("%c ", U[i]);
    printf("}\n");


    unionSet(A, nA, B, nB);
    intersectionSet(A, nA, B, nB);
    differenceSet(A, nA, B, nB);

    
    if (isSubset(A, nA, B, nB))
        printf("A is subset of B\n");
    else
        printf("A is NOT subset of B\n");

    
    if (isSubset(B, nB, A, nA))
        printf("A is superset of B\n");
    else
        printf("A is NOT superset of B\n");

    
    cartesianProduct(A, nA, B, nB);

    
    powerSet(A, nA);

    return 0;
}   
    