class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {

        if (nums.size() < 3)
            return 0;

        vector<int> dp(nums.size() + 1, 0);

        dp[0] = 0;
        dp[1] = 0;
        int d = nums[1] - nums[0];
        int s = 0, ans = 0;
        for (int i = 2; i < nums.size(); i++)
        {

            if (nums[i] - nums[i - 1] == d && (i - s + 1) >= 3)
            {

                dp[i] = dp[i - 1] + (i - s - 1);
            }
            else if (nums[i] - nums[i - 1] != d)
            {
                dp[i] = dp[i - 1];
                s = i - 1;
                d = nums[i] - nums[i - 1];
            }
            else
            {
                dp[i] = dp[i - 1];
            }
        }

        return dp[nums.size() - 1];
    }
};