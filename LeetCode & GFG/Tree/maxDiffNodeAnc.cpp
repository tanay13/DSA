class Solution
{
public:
    void recFunc(TreeNode *root, vector<int> &vec, int mx, int mn)
    {

        if (root == NULL)
            return;

        mx = max(mx, root->val);
        mn = min(mn, root->val);

        recFunc(root->left, vec, mx, mn);
        recFunc(root->right, vec, mx, mn);

        int el = max(abs(mx - (root->val)), abs(mn - (root->val)));
        vec.push_back(el);

        return;
    }

    int maxAncestorDiff(TreeNode *root)
    {

        vector<int> vec;

        recFunc(root, vec, INT_MIN, INT_MAX);

        return *max_element(vec.begin(), vec.end());
    }
};