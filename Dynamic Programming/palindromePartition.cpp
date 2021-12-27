int dp[501][501];
int check_palindrome(string &str, int i, int j)
{
    for (int k = i; k <= j; k++, j--)
    {
        if (str[k] != str[j])
        {
            return 0;
        }
    }
    return 1;
}
int solve(string &str, int i, int j)
{
    // Base Cases
    if (i >= j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];

    if (check_palindrome(str, i, j))
    {
        return 0;
    }

    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int temp = solve(str, i, k) + solve(str, k + 1, j);
        ans = min(ans, temp + 1);
    }
    return dp[i][j] = ans;
}
int palindromicPartition(string str)
{
    // code here
    memset(dp, -1, sizeof(dp));
    return solve(str, 0, str.length() - 1);
}