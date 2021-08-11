class Solution
{
public:
    bool bipar(int src, vector<vector<int>> &graph, vector<int> &colored)
    {
        queue<int> q;

        q.push(src);
        colored[src] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto it : graph[node])
            {
                if (colored[it] == -1)
                {
                    q.push(it);
                    colored[it] = 1 - colored[node];
                }
                else if (colored[it] == colored[node])
                    return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>> &graph)
    {

        int V = graph.size();
        vector<int> colored(V, -1);

        for (int i = 0; i < V; i++)
        {

            if (colored[i] == -1)
            {
                if (!bipar(i, graph, colored))
                {
                    return false;
                }
            }
        }

        return true;
    }
};