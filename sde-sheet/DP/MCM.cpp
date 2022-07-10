#include <vector>

int func(vector<vector<int>> &dp, vector<int> &arr, int i, int j)
{
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;

    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + func(dp, arr, i, k) + func(dp, arr, k + 1, j);
        ans = min(ans, steps);
    }

    return dp[i][j] = ans;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));

    return func(dp, arr, 1, N - 1);
}

// Tabulation

#include <vector>

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    int dp[N][N];

    for (int i = 0; i < N; i++)
        dp[i][i] = 0;

    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            int val = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                val = min(val, steps);
            }
            dp[i][j] = val;
        }
    }

    return dp[1][N - 1];
}