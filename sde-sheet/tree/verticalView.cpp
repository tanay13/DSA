/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {

        stack<pair<TreeNode *, pair<int, int>>> s;

        vector<vector<int>> ans;

        s.push({root, {0, 0}});

        map<pair<int, int>, vector<int>> m;

        while (s.size() > 0)
        {

            auto node = s.top().first;
            int x = s.top().second.first;
            int y = s.top().second.second;

            s.pop();

            m[{x, y}].push_back(node->val);

            if (node->right)
            {
                s.push({node->right, {x + 1, y + 1}});
            }
            if (node->left)
            {
                s.push({node->left, {x - 1, y + 1}});
            }
        }

        map<int, vector<int>> mp;

        for (auto it : m)
        {
            sort(it.second.begin(), it.second.end());
            for (auto i : it.second)
                mp[it.first.first].push_back(i);
        }

        for (auto it : mp)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};