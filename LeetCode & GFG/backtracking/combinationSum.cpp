class Solution
{
public:
    void backtrack(vector<vector<int>> &ans, vector<int> &candidates, int target, int index, vector<int> &vec)
    {
        if (target < 0)
            return;

        if (target == 0)
        {
            ans.push_back(vec);
            return;
        }

        if (index > candidates.size() - 1)
            return;

        backtrack(ans, candidates, target, index + 1, vec);

        vec.push_back(candidates[index]);

        backtrack(ans, candidates, target - candidates[index], index, vec);

        vec.pop_back();

        return;
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {

        vector<vector<int>> ans;
        vector<int> vec;

        backtrack(ans, candidates, target, 0, vec);

        return ans;
    }
};