#include <stdio.h>

#define MAX 50


int pascal_recursive(int n, int k)
{
    if (k == 0 || k == n)
        return 1;

    return pascal_recursive(n-1, k-1) +
           pascal_recursive(n-1, k);
}


int memo[MAX][MAX];

int pascal_memo(int n, int k)
{
    if (memo[n][k] != -1)
        return memo[n][k];

    if (k == 0 || k == n)
        return memo[n][k] = 1;

    memo[n][k] = pascal_memo(n-1, k-1) +
                 pascal_memo(n-1, k);

    return memo[n][k];
}


void pascal_iterative(int n)
{
    int dp[MAX][MAX];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];

            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    int n, choice;

    printf("Enter order of Pascal Triangle: ");
    scanf("%d", &n);

    printf("\nChoose Method:\n");
    printf("1. Naive Recursive\n");
    printf("2. Memoized Recursive\n");
    printf("3. Iterative DP (Non-Recursive)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
                printf("%d ", pascal_recursive(i, j));
            printf("\n");
        }
    }

    else if (choice == 2)
    {
        for (int i = 0; i < MAX; i++)
            for (int j = 0; j < MAX; j++)
                memo[i][j] = -1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
                printf("%d ", pascal_memo(i, j));
            printf("\n");
        }
    }

    else if (choice == 3)
    {
        pascal_iterative(n);
    }

    else
    {
        printf("Invalid Choice!\n");
    }

    return 0;
}
