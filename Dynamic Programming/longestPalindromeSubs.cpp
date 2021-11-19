class Solution
{
public:
    int ans(vector<vector<int>> &dp, string &s, int n, int i, int j)
    {

        if (i > j)
            return 0;

        if (i == j)
            return dp[i][j] = 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j])
        {
            dp[i][j] = 2 + ans(dp, s, n, i + 1, j - 1);
            return dp[i][j];
        }

        dp[i][j] = max(ans(dp, s, n, i + 1, j), ans(dp, s, n, i, j - 1));

        return dp[i][j];
    }

    int longestPalindromeSubseq(string s)
    {

        int n = s.length();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return ans(dp, s, n, 0, n - 1);
    }
};