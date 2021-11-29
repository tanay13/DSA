class Solution
{
public:
    void dfs(vector<vector<int>> &graph, vector<vector<int>> &allPath, vector<int> &path, int curr)
    {

        path.push_back(curr);

        if (curr == graph.size() - 1)
            allPath.push_back(path);
        else
        {
            for (int it : graph[curr])
                dfs(graph, allPath, path, it);
        }

        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {

        vector<vector<int>> allPath;

        vector<int> path;

        dfs(graph, allPath, path, 0);

        return allPath;
    }
};