
long long costDP(vector<int> &cost, int index, vector<long long> &dp)
{

    if (index > cost.size())
    {
        return INT_MAX;
    }

    if (index == cost.size())
    {

        return 0;
    }

    if (dp[index] != -1)
        return dp[index];

    dp[index] = cost[index] + min(costDP(cost, index + 1, dp), costDP(cost, index + 2, dp));

    return dp[index];
}

long long minCostClimbingStairs(vector<int> &cost)
{

    vector<long long> dp(1001, -1);

    return min(costDP(cost, 0, dp), costDP(cost, 1, dp));
}
