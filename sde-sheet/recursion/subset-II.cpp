class Solution
{
public:
    void rec(vector<int> &nums, int idx, vector<vector<int>> &ans, vector<int> &a)
    {

        ans.push_back(a);
        for (int i = idx; i < nums.size(); i++)
        {

            if (i != idx && nums[i] == nums[i - 1])
                continue;

            a.push_back(nums[i]);
            rec(nums, i + 1, ans, a);
            a.pop_back();
        }

        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {

        vector<vector<int>> ans;
        vector<int> a;
        sort(nums.begin(), nums.end());
        rec(nums, 0, ans, a);

        return ans;
    }
};