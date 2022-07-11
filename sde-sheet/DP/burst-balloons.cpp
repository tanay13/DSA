class Solution
{
public:
    int func(vector<int> &nums, vector<vector<int>> &dp, int i, int j)
    {

        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int mxCost = INT_MIN;

        for (int k = i; k <= j; k++)
        {
            // assuming kth balloon is bursted at the end between the interval of i to j
            int cost = nums[i - 1] * nums[k] * nums[j + 1] + func(nums, dp, i, k - 1) + func(nums, dp, k + 1, j);

            mxCost = max(mxCost, cost);
        }

        return dp[i][j] = mxCost;
    }

    int maxCoins(vector<int> &nums)
    {

        int n = nums.size();

        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

        return func(nums, dp, 1, n);
    }
};