public:
void bfs(queue<int> &q, int el, vector<int> &indegree, vector<int> &topo, vector<int> adj[])
{

    while (!q.empty())
    {
        int node = q.front();
        topo.push_back(node);
        q.pop();

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    return;
}

// Function to return list containing vertices in Topological order.
vector<int> topoSort(int V, vector<int> adj[])
{
    // code here

    vector<int> indegree(V + 1, 0);
    vector<int> topo;
    vector<int> ans;
    queue<int> q;

    for (int i = 0; i < V; i++)
    {

        for (int it : adj[i])
        {
            indegree[it]++;
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    for (int i = 0; i < V; i++)
    {

        bfs(q, i, indegree, topo, adj);
    }

    for (int i = topo.size() - 1; i >= 0; i--)
    {
        ans.push_back(topo[i]);
    }

    return topo;
}