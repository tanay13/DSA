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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {

        vector<vector<int>> ans;
        queue<TreeNode *> q;

        if (root == NULL)
            return ans;

        q.push(root);

        int f = 0;

        while (q.size() > 0)
        {

            int sz = q.size();
            vector<int> v(sz);

            for (int i = 0; i < sz; i++)
            {
                auto node = q.front();
                v[i] = node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                q.pop();
            }

            if (f == 1)
            {
                reverse(v.begin(), v.end());
                f = 0;
            }
            else
            {
                f = 1;
            }

            ans.push_back(v);
        }

        return ans;
    }
};