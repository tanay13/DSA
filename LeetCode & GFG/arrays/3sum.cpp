class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        set<vector<int>> v;
        vector<vector<int>> ans;
        if (nums.size() < 3)
        {
            return ans;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++)
        {

            if (i != 0 && nums[i] == nums[i - 1])
                continue;

            int target = 0 - nums[i];

            int s = i + 1;
            int e = nums.size() - 1;

            while (s < e)
            {
                if (s > nums.size())
                    break;

                if (nums[s] + nums[e] > target)
                {
                    e--;
                    continue;
                }
                if (nums[s] + nums[e] < target)
                {
                    s++;
                    continue;
                }

                if (nums[s] + nums[e] == target)
                {

                    vector<int> a;
                    a.push_back(nums[i]);
                    a.push_back(nums[s]);
                    a.push_back(nums[e]);
                    v.insert(a);

                    s++;
                }
            }
        }

        for (auto i : v)
            ans.push_back(i);

        return ans;
    }
};