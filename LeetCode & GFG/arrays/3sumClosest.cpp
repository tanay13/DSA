class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {

        sort(nums.begin(), nums.end());

        int sum1 = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size() - 2; i++)
        {

            int s = i + 1;
            int e = nums.size() - 1;

            while (s < e)
            {

                int sum = nums[i] + nums[s] + nums[e];

                if (sum == target)
                    return sum;

                if (abs(sum - target) < abs(sum1 - target))
                    sum1 = sum;

                if (sum > target)
                    e--;
                else
                    s++;
            }
        }

        return sum1;
    }
};