
class Solution
{
public:
    bool dfs(int i, vector<int> &visited, vector<int> adj[], vector<int> &dfsq)
    {

        visited[i] = 1;
        dfsq[i] = 1;

        for (auto it : adj[i])
        {
            if (visited[it] == 0)
            {
                if (dfs(it, visited, adj, dfsq))
                    return true;
            }
            else if (dfsq[it] == 1)
                return true;
        }
        dfsq[i] = 0;
        return false;
    }

    //Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        vector<int> visited(V, 0);
        vector<int> dfsq(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                if (dfs(i, visited, adj, dfsq))
                    return true;
            }
        }

        return false;
    }
};