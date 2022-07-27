class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {

        vector<int> dp(nums.size() + 1, 0);

        deque<pair<int, int>> deq;

        dp[nums.size() - 1] = nums[nums.size() - 1];

        deq.push_back({nums[nums.size() - 1], nums.size() - 1});

        for (int i = nums.size() - 2; i >= 0; i--)
        {

            while (deq.front().second > i + k)
                deq.pop_front();

            dp[i] = nums[i] + deq.front().first;

            while (deq.size() > 0 && dp[i] > deq.back().first)
            {
                deq.pop_back();
            }

            deq.push_back({dp[i], i});
        }

        return dp[0];
    }
};