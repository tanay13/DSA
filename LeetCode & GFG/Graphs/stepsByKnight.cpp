class Solution
{
public:
    //Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        // Code here
        vector<pair<int, int>> moves{{-1, 2}, {1, 2}, {2, 1}, {-2, 1}, {-2, -1}, {2, -1}, {-1, -2}, {1, -2}};

        unordered_map<pair<int, int>, vector<pair<int, int>>> adj;

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {

                for (int k = 0; k < moves.size(); k++)
                {
                    int x = i + moves[k].first;
                    int y = j + moves[k].second;

                    if ((x <= N && x >= 1) && (y <= N && y >= 1))
                        adj[{i, j}].push_back({x, y});
                }
            }
        }

        vector<pair<int, int>> dist(N * N, INT_MAX);

        queue<pair<int, int>> q;

        dist[{KnightPos[0], KnightPos[1]}] = 0;

        q.push({KnightPos[0], KnightPos[1]});

        while (!q.empty())
        {
            pair<int, int> p = q.front();

            for (auto it : adj[p])
            {
                if (dist[p] + 1 < dist[{it.first, it.second}])
                {
                    dist[{it.first, it.second}] = dist[p] + 1;
                    q.push({it.first, it.second});
                }
            }
        }

        return dist[{TargetPos[0], TargetPos[1]}];
    }
};
