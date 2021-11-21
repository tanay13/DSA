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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {

        map<int, int> in;

        for (int i = 0; i < inorder.size(); i++)
            in[inorder[i]] = i;

        int e = postorder.size() - 1;
        int s = 0;

        return build(postorder, in, s, e, e);
    }

    TreeNode *build(vector<int> &postorder, map<int, int> &in, int s, int e, int &index)
    {

        if (index < 0 || s > e)
            return NULL;

        TreeNode *head = new TreeNode(postorder[index--]);

        int curr = in[head->val];

        head->right = build(postorder, in, curr + 1, e, index);
        head->left = build(postorder, in, s, curr - 1, index);

        return head;
    }
};