#include <stdio.h>

#define THRESHOLD 10  


void insertionSort(int data[], int start, int end) {
    for (int p = start + 1; p <= end; p++) {
        int temp = data[p];
        int q = p - 1;

        while (q >= start && data[q] > temp) {
            data[q + 1] = data[q];
            q--;
        }
        data[q + 1] = temp;
    }
}


void merge(int data[], int start, int middle, int end) {
    int sizeA = middle - start + 1;
    int sizeB = end - middle;

    int leftBlock[sizeA], rightBlock[sizeB];

    for (int x = 0; x < sizeA; x++)
        leftBlock[x] = data[start + x];

    for (int y = 0; y < sizeB; y++)
        rightBlock[y] = data[middle + 1 + y];

    int i1 = 0, i2 = 0, pos = start;

    while (i1 < sizeA && i2 < sizeB) {
        if (leftBlock[i1] <= rightBlock[i2])
            data[pos++] = leftBlock[i1++];
        else
            data[pos++] = rightBlock[i2++];
    }

    while (i1 < sizeA)
        data[pos++] = leftBlock[i1++];

    while (i2 < sizeB)
        data[pos++] = rightBlock[i2++];
}


void hybridMergeSort(int data[], int start, int end) {
    if (start < end) {

        
        if (end - start + 1 <= THRESHOLD) {
            insertionSort(data, start, end);
            return;
        }

        int middle = start + (end - start) / 2;

        hybridMergeSort(data, start, middle);
        hybridMergeSort(data, middle + 1, end);

        merge(data, start, middle, end);
    }
}

int main() {
    int total;
    printf("Enter number of elements: ");
    scanf("%d", &total);

    int data[total];

    printf("Enter %d integers:\n", total);
    for (int k = 0; k < total; k++)
        scanf("%d", &data[k]);

    hybridMergeSort(data, 0, total - 1);

    printf("Sorted array:\n");
    for (int k = 0; k < total; k++)
        printf("%d ", data[k]);

    printf("\n");
    return 0;
}
