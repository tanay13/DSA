public:
// Function to find the shortest distance of all the vertices
// from the source vertex S.
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here

    vector<int> dist(V + 1, INT_MAX);
    dist[S] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push(make_pair(0, S));

    while (pq.size() > 0)
    {

        auto node = pq.top().second;

        pq.pop();

        for (auto it : adj[node])
        {

            if (dist[node] + it[1] < dist[it[0]])
            {
                dist[it[0]] = dist[node] + it[1];
                pq.push(make_pair(dist[it[0]], it[0]));
            }
        }
    }

    return dist;
}
