class Solution
{
public:
    // memoization
    int func(vector<int> &dp, vector<int> &cost, int n, int i)
    {

        if (i > n - 1)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        return dp[i] = cost[i] + min(func(dp, cost, n, i + 1), func(dp, cost, n, i + 2));
    }

    int minCostClimbingStairs(vector<int> &cost)
    {

        int n = cost.size();

        //         vector<int> dp(n+1,-1);

        //         return min(func(dp,cost,n,0),func(dp,cost,n,1));

        // tabulation
        vector<int> dp(n + 1);

        for (int i = 2; i <= n; i++)
        {

            int jOne = cost[i - 1] + dp[i - 1];
            int jTwo = cost[i - 2] + dp[i - 2];

            dp[i] = min(jOne, jTwo);
        }

        return dp[n];
    }
};