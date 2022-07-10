class Solution
{
public:
    int func(vector<vector<int>> &dp, vector<int> &cuts, int i, int j)
    {

        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int minCost = INT_MAX;

        for (int k = i; k <= j; k++)
        {
            int cost = cuts[j + 1] - cuts[i - 1] + func(dp, cuts, i, k - 1) + func(dp, cuts, k + 1, j);
            minCost = min(minCost, cost);
        }

        return dp[i][j] = minCost;
    }

    int minCost(int N, vector<int> &cuts)
    {

        int n = cuts.size();

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

        cuts.push_back(N);

        cuts.insert(cuts.begin(), 0);

        sort(cuts.begin(), cuts.end());

        // till n because two new elements are added in the cuts vector
        // so the range will be from 1st el of the original cuts array to last element of org cuts array
        return func(dp, cuts, 1, n);
    }
};