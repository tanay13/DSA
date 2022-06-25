class Solution
{
public:
    int func(vector<int> &p, int i, int b, vector<vector<vector<int>>> &dp, int k)
    {

        if (i > p.size() - 1 || k == 0)
            return 0;

        if (dp[i][b][k] != -1)
            return dp[i][b][k];

        if (b == 0)
        {
            return dp[i][b][k] = max(-p[i] + func(p, i + 1, 1, dp, k), func(p, i + 1, 0, dp, k));
        }
        else
        {
            return dp[i][b][k] = max(p[i] + func(p, i + 1, 0, dp, k - 1), func(p, i + 1, b, dp, k));
        }

        return 0;
    }

    int maxProfit(vector<int> &p)
    {

        vector<vector<vector<int>>> dp(p.size() + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return func(p, 0, 0, dp, 2);
    }
};