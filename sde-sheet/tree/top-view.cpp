
#include <stack>
#include <map>
#include <vector>

vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.

    queue<pair<TreeNode<int> *, int>> q;

    vector<int> ans;

    if (root == NULL)
        return ans;

    q.push({root, 0});

    map<int, int> m;

    while (q.size() > 0)
    {

        auto node = q.front().first;
        int x = q.front().second;

        q.pop();
        if (m.find(x) == m.end())
            m[x] = node->val;

        if (node->right)
        {
            q.push({node->right, x + 1});
        }
        if (node->left)
        {
            q.push({node->left, {x - 1}});
        }
    }

    for (auto it : m)
    {
        ans.push_back(it.second);
    }

    return ans;
}