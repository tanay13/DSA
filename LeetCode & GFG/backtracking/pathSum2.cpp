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
    void dfs(TreeNode *root, int targetSum, vector<int> &a, vector<vector<int>> &ans)
    {
        if (root == NULL)
            return;

        a.push_back(root->val);

        if (targetSum == root->val && root->left == NULL && root->right == NULL)
        {
            ans.push_back(a);
            a.pop_back();
            return;
        }

        dfs(root->left, targetSum - root->val, a, ans);
        dfs(root->right, targetSum - root->val, a, ans);

        a.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {

        vector<vector<int>> ans;
        vector<int> a;

        dfs(root, targetSum, a, ans);

        return ans;
    }
};