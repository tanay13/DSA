// topological sort only possible in DAG (Directed Acyclic Graph)

class Solution
{
public:
    void dfs(int src, vector<int> adj[], vector<int> &v, stack<int> &s)
    {
        queue<int> q;
        q.push(src);
        v[src] = 1;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it : adj[node])
            {
                if (v[it] == 0)
                {
                    dfs(it, adj, v, s);
                }
            }
        }

        s.push(src);

        return;
    }

    //Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // code here

        vector<int> v(V, 0);

        vector<int> ans;

        stack<int> s;

        for (int i = 0; i < V; i++)
        {
            if (v[i] == 0)
            {
                dfs(i, adj, v, s);
            }
        }

        while (!s.empty())
        {
            int node = s.top();
            s.pop();
            ans.push_back(node);
        }

        return ans;
    }
};
