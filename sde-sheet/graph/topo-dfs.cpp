class Solution
{
public:
    void dfs(int node, vector<int> &vis, stack<int> &s, vector<int> adj[])
    {

        if (vis[node] == 1)
            return;

        vis[node] = 1;

        for (auto it : adj[node])
        {
            dfs(it, vis, s, adj);
        }

        s.push(node);
    }

    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // code here
        stack<int> s;
        vector<int> vis(V + 1, -1);

        for (int i = 0; i < V; i++)
        {
            if (vis[i] == -1)
            {
                dfs(i, vis, s, adj);
            }
        }

        vector<int> topo;

        while (!s.empty())
        {
            int n = s.top();
            s.pop();

            topo.push_back(n);
        }

        return topo;
    }
};