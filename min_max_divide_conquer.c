#include <stdio.h>

struct Result {
    int min, max;
    int min_pos, max_pos;
};

struct Result MinMax(int A[], int low, int high)
{
    struct Result r, r1, r2;
    int mid;


    if (low == high) {
        r.min = r.max = A[low];
        r.min_pos = r.max_pos = low;
        return r;
    }

    
    if (high == low + 1) {
        if (A[low] < A[high]) {
            r.min = A[low];  r.max = A[high];
            r.min_pos = low; r.max_pos = high;
        } else {
            r.min = A[high]; r.max = A[low];
            r.min_pos = high; r.max_pos = low;
        }
        return r;
    }

    
    mid = (low + high) / 2;

    r1 = MinMax(A, low, mid);
    r2 = MinMax(A, mid + 1, high);


    if (r1.min < r2.min) {
        r.min = r1.min;
        r.min_pos = r1.min_pos;
    } else {
        r.min = r2.min;
        r.min_pos = r2.min_pos;
    }


    if (r1.max > r2.max) {
        r.max = r1.max;
        r.max_pos = r1.max_pos;
    } else {
        r.max = r2.max;
        r.max_pos = r2.max_pos;
    }

    return r;
}

int main()
{
    int A[100], n, i;
    struct Result res;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    res = MinMax(A, 0, n - 1);

    printf("Minimum value = %d at position %d\n", res.min, res.min_pos);
    printf("Maximum value = %d at position %d\n", res.max, res.max_pos);

    return 0;
}
