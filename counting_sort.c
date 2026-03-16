#include<stdio.h>

int main(){
   int n,k;
   printf("enter the number of elements:");
   scanf("%d",&n);

   int arr[n];

   printf("enter the elements (range 0 to k):\n");
   for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
   }

   printf("enter maximum value k:");
   scanf("%d", &k);

   int count[k + 1];
   int output[n];

   for(int i = 0; i <= k; i++){
        count[i] = 0;
   }

   for(int i = 0; i < n; i++){
          count[arr[i]]++;
   }

   for(int i = 1; i <= k; i++){
       count[i] += count[i - 1];
   }

   for(int i = n - 1; i >= 0; i--){
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
   }

   for(int i = 0; i < n; i++){
         arr[i] = output[i];
   }

   printf("sorted array: \n");
   for(int i = 0; i < n; i++){
       printf("%d \t", arr[i]);
   }

 return 0;
}