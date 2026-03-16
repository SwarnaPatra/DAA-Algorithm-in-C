#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void exchange(int *x, int *y) {
    int tempVal = *x;
    *x = *y;
    *y = tempVal;
}


int fixedPartition(int data[], int start, int end) {
    int pivotVal = data[start];
    int pos = start + 1;

    for (int idx = start + 1; idx <= end; idx++) {
        if (data[idx] < pivotVal) {
            exchange(&data[pos], &data[idx]);
            pos++;
        }
    }
    exchange(&data[start], &data[pos - 1]);
    return pos - 1;
}


void quickSortFixed(int data[], int start, int end) {
    if (start < end) {
        int pivotLoc = fixedPartition(data, start, end);
        quickSortFixed(data, start, pivotLoc - 1);
        quickSortFixed(data, pivotLoc + 1, end);
    }
}


int randomPartition(int data[], int start, int end) {
    int randPos = start + rand() % (end - start + 1);
    exchange(&data[start], &data[randPos]);
    return fixedPartition(data, start, end);
}


void quickSortRandom(int data[], int start, int end) {
    if (start < end) {
        int pivotLoc = randomPartition(data, start, end);
        quickSortRandom(data, start, pivotLoc - 1);
        quickSortRandom(data, pivotLoc + 1, end);
    }
}


void displayArray(int data[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", data[i]);
    printf("\n");
}


int main() {
    srand(time(0));

    int size;
    printf("Enter number of elements: ");
    scanf("%d", &size);

    int listA[size], listB[size];

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &listA[i]);
        listB[i] = listA[i];
    }

    printf("\nOriginal array: ");
    displayArray(listA, size);

    quickSortFixed(listA, 0, size - 1);
    printf("Sorted with fixed pivot: ");
    displayArray(listA, size);

    quickSortRandom(listB, 0, size - 1);
    printf("Sorted with randomized pivot: ");
    displayArray(listB, size);

    return 0;
}
