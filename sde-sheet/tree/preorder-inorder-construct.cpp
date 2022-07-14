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
    int index = 0;

    TreeNode *construct(vector<int> &preorder, vector<int> &inorder, int s, int e, map<int, int> &m)
    {

        if (s > e)
            return NULL;

        int val = preorder[index++];

        TreeNode *node = new TreeNode(val);

        int currIndex = m[val];

        node->left = construct(preorder, inorder, s, currIndex - 1, m);
        node->right = construct(preorder, inorder, currIndex + 1, e, m);

        return node;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {

        map<int, int> m;
        int n = preorder.size();

        for (int i = 0; i < n; i++)
            m[inorder[i]] = i;

        int s = 0, e = n - 1;

        return construct(preorder, inorder, s, e, m);
    }
};