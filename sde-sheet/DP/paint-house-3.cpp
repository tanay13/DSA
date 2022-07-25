class Solution
{
public:
    int mx = 1e7;

    int func(vector<int> &h, vector<vector<int>> &c, int n, int target, int i, int prev, int count, vector<vector<vector<int>>> &dp)
    {

        if (i == h.size() && count == target)
            return 0;

        if ((i == h.size() && (count > target || count < target)) || i < h.size() && count > target)
            return mx;

        if (dp[i][prev][count] != -1)
            return dp[i][prev][count];

        int cost = mx;

        if (h[i])
        {
            if (prev == h[i])
                cost = func(h, c, n, target, i + 1, prev, count, dp);
            else
                cost = func(h, c, n, target, i + 1, h[i], count + 1, dp);
        }
        else
        {
            for (int p = 0; p < n; p++)
            {
                if (prev == p + 1)
                {
                    cost = min(cost, c[i][p] + func(h, c, n, target, i + 1, prev, count, dp));
                }
                else
                {
                    cost = min(cost, c[i][p] + func(h, c, n, target, i + 1, p + 1, count + 1, dp));
                }
            }
        }

        return dp[i][prev][count] = cost;
    }

    int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target)
    {

        vector<vector<vector<int>>> dp(m + 2, vector<vector<int>>(n + 3, vector<int>(target + 3, -1)));

        int ans = func(houses, cost, n, target, 0, 0, 0, dp);

        if (ans == mx)
            return -1;
        return ans;
    }
};