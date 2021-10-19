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
    bool hasPathSum(TreeNode *root, int targetSum)
    {

        if (root == NULL)
            return false;

        stack<pair<TreeNode *, int>> s;

        s.push({root, root->val});

        while (s.size() > 0)
        {
            auto node = s.top().first;
            int sum = s.top().second;
            s.pop();

            if (!node->left && !node->right && sum == targetSum)
            {
                return true;
            }

            if (node->left)
            {
                int a = (node->left)->val;
                s.push({node->left, sum + a});
            }

            if (node->right)
            {
                int a = (node->right)->val;
                s.push({node->right, sum + a});
            }
        }

        return false;
    }
};