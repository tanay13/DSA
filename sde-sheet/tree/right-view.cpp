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
    vector<int> rightSideView(TreeNode *root)
    {

        queue<pair<TreeNode *, int>> q;

        vector<int> ans;

        if (root == NULL)
            return ans;

        q.push({root, 0});

        map<int, int> m;

        while (q.size() > 0)
        {

            auto node = q.front().first;
            int y = q.front().second;

            q.pop();

            m[y] = node->val;
            if (node->left)
            {
                q.push({node->left, {y + 1}});
            }
            if (node->right)
            {
                q.push({node->right, y + 1});
            }
        }

        for (auto it : m)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};