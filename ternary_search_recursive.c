#include <stdio.h>

int TernarySearch(int A[], int key, int lb, int ub)
{
    int mid1, mid2;

    if (lb > ub)
        return -1;

    mid1 = lb + (ub - lb) / 3;
    mid2 = ub - (ub - lb) / 3;

    if (A[mid1] == key)
        return mid1;

    if (A[mid2] == key)
        return mid2;

    if (key < A[mid1])
        return TernarySearch(A, key, lb, mid1 - 1);

    else if (key > A[mid2])
        return TernarySearch(A, key, mid2 + 1, ub);

    else
        return TernarySearch(A, key, mid1 + 1, mid2 - 1);
}

int main()
{
    int A[100], n, key, i, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements in non-decreasing order:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    printf("Enter key to search: ");
    scanf("%d", &key);

    pos = TernarySearch(A, key, 0, n - 1);

    if (pos == -1)
        printf("Key not found.\n");
    else
        printf("Key found at position %d (index %d).\n", pos + 1, pos);

    return 0;
}
