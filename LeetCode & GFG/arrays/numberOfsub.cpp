class Solution
{
public:
    int mod = 1000000007;
    int numSubseq(vector<int> &nums, int target)
    {

        vector<int> power = {1};
        for (int i = power.size(); i < nums.size(); i++)
        {
            power.push_back((power.back() << 1) % mod);
        }

        sort(nums.begin(), nums.end());

        int s = 0;
        int e = nums.size() - 1;

        int c = 0;

        while (s <= e)
        {

            if (s == e && nums[s] + nums[e] <= target)
            {

                c++;
                break;
            }

            if (nums[s] + nums[e] > target)
            {
                e--;
                continue;
            }

            if (nums[s] + nums[e] <= target)
            {
                c = (c % mod + power[e - s] % mod) % mod;
                s++;
            }
        }

        return c;
    }
};