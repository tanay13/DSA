class Solution
{
public:
    bool dfs(int node, vector<int> &visited, vector<int> &dfsq, vector<int> graph[])
    {
        visited[node] = 1;
        dfsq[node] = 1;

        for (auto it : graph[node])
        {
            if (visited[it] != 1)
            {
                if (dfs(it, visited, dfsq, graph))
                    return true;
            }
            else if (dfsq[it] == 1)
                return true;
        }
        dfsq[node] = 0;

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {

        vector<int> graph[numCourses];

        for (auto i : prerequisites)
        {
            graph[i[1]].push_back(i[0]);
        }

        vector<int> visited(numCourses + 1, -1);

        vector<int> dfsq(numCourses + 1, -1);

        for (int i = 0; i < numCourses; i++)
        {
            if (visited[i] == -1)
            {
                if (dfs(i, visited, dfsq, graph))
                {
                    return false;
                }
            }
        }

        return true;
    }
};