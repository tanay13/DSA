class Solution
{
public:
    int func(vector<vector<vector<int>>> &dp, vector<int> &p, int k, int i, int ls)
    {

        if (i > p.size() - 1 || k == 0)
            return 0;

        if (dp[i][k][ls] != -1)
            return dp[i][k][ls];

        if (ls == 0)
        {
            return dp[i][k][ls] = max(-p[i] + func(dp, p, k, i + 1, 1), func(dp, p, k, i + 1, 0));
        }
        else
        {
            return dp[i][k][ls] = max(p[i] + func(dp, p, k - 1, i + 1, 0), func(dp, p, k, i + 1, 1));
        }
        return 0;
    }

    int maxProfit(int k, vector<int> &p)
    {

        if (p.size() == 0)
            return 0;

        vector<vector<vector<int>>> dp(p.size() + 1, vector<vector<int>>(k + 1, vector<int>(2, -1)));

        return func(dp, p, k, 0, 0);
    }
};