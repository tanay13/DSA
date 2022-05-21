class Solution
{
public:
    /*  Function to implement Dijkstra
     *   adj: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellman_ford(int V, vector<vector<int>> adj, int S)
    {
        // Code here

        vector<int> dist(V + 1, 1e8);

        dist[S] = 0;

        for (int i = 0; i < V; i++)
        {

            for (int j = 0; j < adj.size(); j++)
            {

                int u = adj[j][0];
                int v = adj[j][1];
                int w = adj[j][2];

                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                }
            }
        }

        return dist;
    }
};