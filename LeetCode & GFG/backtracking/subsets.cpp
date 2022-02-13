class Solution
{
public:
    void backtrack(vector<int> &nums, int index, vector<vector<int>> &ans, vector<int> vec)
    {

        if (index > nums.size() - 1)
        {
            ans.push_back(vec);
            return;
        }

        backtrack(nums, index + 1, ans, vec);

        vec.push_back(nums[index]);

        backtrack(nums, index + 1, ans, vec);

        return;
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {

        vector<vector<int>> ans;
        vector<int> vec;
        backtrack(nums, 0, ans, vec);

        return ans;
    }
};