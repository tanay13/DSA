class Solution
{
public:
    vector<int> ans;

    void path(vector<int> &par, int n)
    {

        if (n == 1)
        {
            ans.push_back(1);
            return;
        }

        ans.push_back(n);

        return path(par, par[n]);
    }

    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // Code here
        vector<int> dist(n + 3, INT_MAX);
        vector<int> par(n + 3);
        for (int i = 0; i < par.size(); i++)
            par[i] = i;
        dist[1] = 0;
        vector<pair<int, int>> graph[n + 1];

        for (auto it : edges)
        {
            graph[it[0]].push_back({it[1], it[2]});
            graph[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, 1});

        while (pq.size() > 0)
        {

            auto it = pq.top().second;
            auto d = pq.top().first;

            pq.pop();

            for (auto i : graph[it])
            {
                auto eW = i.second;
                auto node = i.first;

                if (d + eW < dist[node])
                {
                    dist[node] = d + eW;
                    par[node] = it;
                    pq.push({dist[node], node});
                }
            }
        }

        if (dist[n] == INT_MAX)
            return {-1};

        path(par, n);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};