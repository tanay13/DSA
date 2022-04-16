// Reverse Inorder

class Solution
{
public:
    int sum = 0;

    void revInorder(TreeNode *root)
    {

        if (root == NULL)
            return;

        revInorder(root->right);
        root->val += sum;
        sum = root->val;
        revInorder(root->left);
        return;
    }

    TreeNode *convertBST(TreeNode *root)
    {

        revInorder(root);
        return root;
    }
};