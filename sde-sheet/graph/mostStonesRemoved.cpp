class Solution
{
public:
    int dfs(int i, vector<int> graph[], vector<int> &vis)
    {

        vis[i] = 1;

        stack<int> s;

        s.push(i);

        int d = 0;

        while (s.size() > 0)
        {
            int node = s.top();
            s.pop();

            for (auto it : graph[node])
            {
                if (vis[it] == -1)
                {
                    vis[it] = 1;
                    s.push(it);
                    cout << node << " IN";
                    d++;
                }
            }
        }

        return d;
    }

    int removeStones(vector<vector<int>> &stones)
    {

        int n = stones.size();

        if (n == 1)
            return 0;

        vector<int> graph[n];

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (auto it : graph[i])
                cout << it << " ";
            cout << "\n";
        }

        vector<int> vis(n, -1);

        int mD = 0;

        for (int i = 0; i < n; i++)
        {
            if (vis[i] == -1)
            {
                int d = dfs(i, graph, vis);
                mD += d;
            }
        }

        return mD;
    }
};