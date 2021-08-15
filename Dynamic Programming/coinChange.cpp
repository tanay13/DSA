int coinChange(vector<int> &coins, int amount)
{
    int M = coins.size();
    int V = amount;
    int dp[M + 1][V + 1];
    //code here.
    for (int i = 0; i < V + 1; i++)
        dp[0][i] = INT_MAX - 1;

    for (int i = 1; i < M + 1; i++)
        dp[i][0] = 0;

    for (int i = 1; i < M + 1; i++)
    {
        for (int j = 1; j < V + 1; j++)
        {
            if (j < coins[i - 1])
                dp[i][j] = dp[i - 1][j];
            else
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
            }
        }
    }
    if (dp[M][V] == INT_MAX - 1)
        return -1;
    else
        return dp[M][V];
}
