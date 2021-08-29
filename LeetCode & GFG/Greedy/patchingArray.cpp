class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {

        long long reachable_sum = 0;
        int add_count = 0;
        int start = 0;

        while (start < nums.size() && reachable_sum < n)
        {

            if (nums[start] > reachable_sum + 1)
            {
                add_count++;
                reachable_sum += reachable_sum + 1;
                continue;
            }

            reachable_sum += nums[start];
            start++;
        }

        //In case the reachable sum is less than n after reaching the last element also

        while (reachable_sum < n)
        {
            add_count++;
            reachable_sum += reachable_sum + 1;
        }

        return add_count;
    }
};