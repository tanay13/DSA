public:
int ans(vector<vector<int>> &dp, int i, int j, string &str)
{

    if (i > str.length() - 1 || j > str.length() - 1)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (str[i] == str[j] && i != j)
    {
        dp[i][j] = 1 + ans(dp, i + 1, j + 1, str);
        return dp[i][j];
    }

    dp[i][j] = max(ans(dp, i + 1, j, str), ans(dp, i, j + 1, str));

    return dp[i][j];
}

int LongestRepeatingSubsequence(string str)
{
    // Code here

    int n = str.length();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    return ans(dp, 0, 0, str);
}
