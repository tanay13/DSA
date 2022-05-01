/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    Node *dfs(Node *node, map<int, Node *> &m)
    {
        if (m.find(node->val) != m.end())
            return m[node->val];

        Node *n1 = new Node(node->val);

        m[n1->val] = n1;

        for (int i = 0; i < node->neighbors.size(); i++)
        {
            n1->neighbors.push_back(dfs(node->neighbors[i], m));
        }

        return n1;
    }

    Node *cloneGraph(Node *node)
    {

        if (node == NULL)
            return NULL;

        map<int, Node *> m;

        return dfs(node, m);
    }
};