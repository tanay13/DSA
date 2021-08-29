class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {

        //Because every element is increasing subsequence on their own
        vector<int> dp(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++)
        {
            int max_till_here = 0;

            // Checking for the max dp[j] value for which nums[i]>nums[j] so that nums[i] can be added to it to the end of nums[j] to make the lIS ending on nums[i];
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (max_till_here < dp[j])
                        max_till_here = dp[j];
                }
            }

            dp[i] += max_till_here;
        }

        return *max_element(dp.begin(), dp.end());
    }
};