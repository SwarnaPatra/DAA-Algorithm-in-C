#include <stdio.h>

#define N 5
#define INF -99999

int grid[N][N] = {
    {4,8,3,6,1},
    {9,7,2,5,11},
    {5,9,2,4,1},
    {7,1,3,6,5},
    {4,1,2,4,5}
};


int naive(int i, int j)
{
    if (i < 0 || j < 0)
        return INF;

    if (i == 0 && j == 0)
        return grid[0][0];

    int fromUp   = naive(i-1, j);
    int fromLeft = naive(i, j-1);

    return grid[i][j] + (fromUp > fromLeft ? fromUp : fromLeft);
}


int memo[N][N];

int dp_recursive(int i, int j)
{
    if (i < 0 || j < 0)
        return INF;

    if (memo[i][j] != -1)
        return memo[i][j];

    if (i == 0 && j == 0)
        return memo[i][j] = grid[0][0];

    int fromUp   = dp_recursive(i-1, j);
    int fromLeft = dp_recursive(i, j-1);

    memo[i][j] = grid[i][j] + (fromUp > fromLeft ? fromUp : fromLeft);
    return memo[i][j];
}

int dp_iterative()
{
    int dp[N][N];

    dp[0][0] = grid[0][0];

    for (int i = 1; i < N; i++)
        dp[i][0] = grid[i][0] + dp[i-1][0];

    for (int j = 1; j < N; j++)
        dp[0][j] = grid[0][j] + dp[0][j-1];

    for (int i = 1; i < N; i++)
        for (int j = 1; j < N; j++)
        {
            int max = dp[i-1][j] > dp[i][j-1] ?
                      dp[i-1][j] : dp[i][j-1];
            dp[i][j] = grid[i][j] + max;
        }

    return dp[N-1][N-1];
}


int main()
{
    int choice;

    printf("Treasure Island Problem\n");
    printf("1. Naive Recursive\n");
    printf("2. Recursive DP (Memoization)\n");
    printf("3. Iterative DP\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
        printf("Maximum Treasure = %d\n", naive(N-1, N-1));

    else if (choice == 2)
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                memo[i][j] = -1;

        printf("Maximum Treasure = %d\n",
               dp_recursive(N-1, N-1));
    }

    else if (choice == 3)
        printf("Maximum Treasure = %d\n",
               dp_iterative());

    else
        printf("Invalid choice\n");

    return 0;
}
