class Solution
{
public:
    int func(vector<int> &p, int i, int b, vector<vector<int>> &dp)
    {

        if (i > p.size() - 1)
            return 0;

        int pr = 0;

        if (dp[i][b] != -1)
            return dp[i][b];

        if (b == 0)
        {
            return dp[i][b] = max(-p[i] + func(p, i + 1, 1, dp), func(p, i + 1, 0, dp));
        }
        else
        {
            return dp[i][b] = max(p[i] + func(p, i + 1, 0, dp), func(p, i + 1, b, dp));
        }

        return 0;
    }

    int maxProfit(vector<int> &p)
    {
        vector<vector<int>> dp(p.size() + 1, vector<int>(2, -1));
        return func(p, 0, 0, dp);
    }
};