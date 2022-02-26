class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &graph)
    {

        int target = (1 << graph.size()) - 1;

        int fin = INT_MAX;

        queue<pair<pair<int, int>, int>> q;

        map<pair<int, int>, int> m;

        for (int i = 0; i < graph.size(); i++)
        {

            int t = (1 << i);

            q.push(make_pair(make_pair(i, t), 0));
        }

        int ans = INT_MAX;

        while (!q.empty())
        {

            auto node = q.front().first.first;
            auto d = q.front().first.second;
            auto p = q.front().second;
            q.pop();

            if (d == target)
            {
                ans = min(ans, p);
                m.erase(make_pair(node, d));
                continue;
            }

            for (int j : graph[node])
            {

                int x = d | (1 << j);

                if (m.find(make_pair(j, x)) != m.end())
                    continue;

                q.push(make_pair(make_pair(j, x), p + 1));

                m[make_pair(j, x)] = 1;
            }
        }

        return ans;
    }
};s