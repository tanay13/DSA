class Solution
{
public:
    int ans(vector<int> &dp, vector<int> &nums, int index)
    {

        if (index > nums.size() - 1)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        dp[index] = max(nums[index] + ans(dp, nums, index + 2), ans(dp, nums, index + 1));

        return dp[index];
    }

    int rob(vector<int> &nums)
    {

        vector<int> dp(nums.size() + 1, -1);

        return ans(dp, nums, 0);
    }
};