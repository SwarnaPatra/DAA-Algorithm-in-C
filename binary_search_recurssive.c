#include <stdio.h>


int BinarySearch(int A[], int key, int lb, int ub)
{
    int mid;

    
    if (lb > ub)
        return -1;

    mid = (lb + ub) / 2;

    
    if (A[mid] == key)
        return mid;


    else if (key < A[mid])
        return BinarySearch(A, key, lb, mid - 1);

    
    else
        return BinarySearch(A, key, mid + 1, ub);
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

    pos = BinarySearch(A, key, 0, n - 1);


    if (pos == -1)
        printf("Key not found in the array.\n");
    else
        printf("Key found at position %d (index %d).\n", pos + 1, pos);

    return 0;
}
