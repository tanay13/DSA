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
    int depth(TreeNode *root, int &ms)
    {
        if (root == NULL)
            return 0;

        int ls = max(0, depth(root->left, ms));
        int rs = max(0, depth(root->right, ms));

        ms = max(ms, root->val + ls + rs);

        return root->val + max(ls, rs);
    }

    int maxPathSum(TreeNode *root)
    {

        if (root == NULL)
            return 0;

        int ms = root->val;

        depth(root, ms);

        return ms;
    }
};