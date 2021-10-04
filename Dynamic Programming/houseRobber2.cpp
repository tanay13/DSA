class Solution
{
public:
    int ans(vector<int> &dp, vector<int> &nums, int index, int end)
    {

        if (index > end)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        dp[index] = max(nums[index] + ans(dp, nums, index + 2, end), ans(dp, nums, index + 1, end));

        return dp[index];
    }

    int rob(vector<int> &nums)
    {

        vector<int> dp(nums.size() + 1, -1);
        vector<int> dp1(nums.size() + 1, -1);

        if (nums.size() < 3)
        {
            sort(nums.begin(), nums.end());
            return nums[nums.size() - 1];
        }

        return max(nums[0] + ans(dp1, nums, 2, nums.size() - 2), ans(dp, nums, 1, nums.size() - 1));
    }
};