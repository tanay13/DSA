class Solution
{
public:
    int minJumps(vector<int> &arr)
    {

        unordered_map<int, vector<int>> m;

        for (int i = 0; i < arr.size(); i++)
        {
            //to avoid TLE (not adding middle same elements like eg:- 1,7,7,7,7,7,3,4   not adding middle 7s in the map)
            if (i + 1 < arr.size() && i - 1 >= 0)
            {
                if (arr[i] == arr[i - 1] && arr[i] == arr[i + 1])
                    continue;
            }
            m[arr[i]].push_back(i);
        }

        vector<int> adj[arr.size()];

        for (int i = 0; i < arr.size(); i++)
        {
            if (i - 1 >= 0)
                adj[i].push_back(i - 1);
            if (i + 1 < arr.size())
                adj[i].push_back(i + 1);

            for (auto it : m[arr[i]])
            {
                if (it != i)
                    adj[i].push_back(it);
            }
        }

        queue<int> q;

        q.push(0);

        vector<int> dist(arr.size(), INT_MAX);

        dist[0] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it : adj[node])
            {
                if (dist[node] + 1 < dist[it])
                {
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }

        return dist[arr.size() - 1];
    }
};