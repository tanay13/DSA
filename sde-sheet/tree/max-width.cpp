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
    int widthOfBinaryTree(TreeNode *root)
    {

        queue<pair<TreeNode *, int>> q;

        q.push({root, 0});

        int mw = INT_MIN;

        while (q.size() > 0)
        {
            int f = 0, l = 0;
            int size = q.size();
            int m = q.front().second;
            for (int i = 0; i < size; i++)
            {
                auto node = q.front().first;
                long long idx = q.front().second - m;
                q.pop();
                if (i == 0)
                    f = idx;
                if (i == size - 1)
                    l = idx;
                if (node->left)
                {
                    q.push({node->left, 2 * idx + 1});
                }

                if (node->right)
                {
                    q.push({node->right, 2 * idx + 2});
                }
            }

            mw = max(mw, l - f + 1);
        }

        return mw;
    }
};