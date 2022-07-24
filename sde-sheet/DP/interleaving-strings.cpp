class Solution
{
public:
    bool func(string s1, string s2, string s3, int i, int j, int k, vector<vector<vector<int>>> &dp)
    {
        if (i == s1.length() && j == s2.length() && k == s3.length())
            return true;

        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        bool x = false, y = false;
        ;

        if (i <= s1.length() - 1 && s1[i] == s3[k])
        {
            x = func(s1, s2, s3, i + 1, j, k + 1, dp);
        }
        if (j <= s2.length() - 1 && s2[j] == s3[k])
        {
            y = func(s1, s2, s3, i, j + 1, k + 1, dp);
        }

        return dp[i][j][k] = x || y;
    }

    bool isInterleave(string s1, string s2, string s3)
    {

        vector<vector<vector<int>>> dp(s1.length() + 2, vector<vector<int>>(s2.length() + 2, vector<int>(s3.length() + 2, -1)));

        return func(s1, s2, s3, 0, 0, 0, dp);
    }
};