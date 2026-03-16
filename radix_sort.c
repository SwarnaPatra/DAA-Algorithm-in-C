#include<stdio.h>

void countingSort(int arr[], int n, int exp, int k){
       int output[n];
       int count[k];

       for(int i = 0; i < k; i++)
           count[i] = 0;

       for(int i = 0; i < n; i++)
          count[ (arr[i] / exp) % k]++;

       for(int i = 1; i < k; i++)
            count[i] += count[i - 1];

       for(int i = n - 1; i >= 0; i--){
            int digit = (arr[i] / exp) % k;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
       }

       for(int i = 0; i < n; i++)
             arr[i] = output[i];
 }

void radixSort(int arr[], int n, int d, int k){
        int exp = 1;
        for(int i = 0; i < d; i++){
            countingSort(arr, n, exp, k);
            exp *= k;
        }
 }

int main(){

    int n, d = 5, k;
    printf("enter number of elements:");
    scanf("%d", &n);

    int arr[n];
    printf("enter the elements:\n");
    for(int i = 0; i < n; i++)
         scanf("%d", &arr[i]);

    printf("enter radix k :");
    scanf("%d", &k);

    radixSort(arr, n, d, k);

    printf("sorted array:\n");
    for(int i = 0; i < n; i++)
        printf("%d \t", arr[i]);


 return 0;
}