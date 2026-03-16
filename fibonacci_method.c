#include <stdio.h>

#define MAX 1000


int fibo_recursive(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return fibo_recursive(n-1) + fibo_recursive(n-2);
}


int memo[MAX];

int fibo_memo(int n)
{
    if (memo[n] != -1)
        return memo[n];

    if (n == 0)
        return memo[n] = 0;
    if (n == 1)
        return memo[n] = 1;

    memo[n] = fibo_memo(n-1) + fibo_memo(n-2);
    return memo[n];
}

int fibo_iterative(int n)
{
    int dp[n+1];

    dp[0] = 0;
    if (n >= 1)
        dp[1] = 1;

    for (int i = 2; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];

    return dp[n];
}


int main()
{
    int n, choice;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("\nChoose Method:\n");
    printf("1. Naive Recursive\n");
    printf("2. Memoized Recursive\n");
    printf("3. Iterative  (Non-Recursive)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Fibonacci(%d) = %d\n", n, fibo_recursive(n));
    }
    else if (choice == 2)
    {
        for (int i = 0; i <= n; i++)
            memo[i] = -1;

        printf("Fibonacci(%d) = %d\n", n, fibo_memo(n));
    }
    else if (choice == 3)
    {
        printf("Fibonacci(%d) = %d\n", n, fibo_iterative(n));
    }
    else
    {
        printf("Invalid Choice!\n");
    }

    return 0;
}
