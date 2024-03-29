long long int count(int S[], int m, int n)
{
    long long int dp[m + 1][n + 1];
    //code here.
    for (long long int i = 0; i < n + 1; i++)
        dp[0][i] = 0;

    for (long long int i = 0; i < m + 1; i++)
        dp[i][0] = 1;

    for (long long int i = 1; i < m + 1; i++)
    {
        for (long long int j = 1; j < n + 1; j++)
        {
            if (j < S[i - 1])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - S[i - 1]];
        }
    }

    return dp[m][n];
}