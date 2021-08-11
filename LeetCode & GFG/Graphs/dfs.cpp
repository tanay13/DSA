class Solution
{
public:
    void dfs(int i, vector<int> adj[], vector<int> &v, vector<int> &visited)
    {
        v.push_back(i);
        visited[i] = 1;

        for (auto it : adj[i])
        {
            if (visited[it] == 0)
                dfs(it, adj, v, visited);
        }
    }
    //Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> visited(V, 0);
        vector<int> v;
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                dfs(i, adj, v, visited);
            }
        }

        return v;
    }
};