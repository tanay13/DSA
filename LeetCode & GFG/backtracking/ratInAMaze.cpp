class Solution
{
public:
    void dfs(int i, int j, string s, vector<vector<int>> &visited, vector<string> &v, vector<vector<int>> &m)
    {

        if (i < 0 || i > m.size() - 1 || j < 0 || j > m[0].size() - 1 || visited[i][j] != -1 || m[i][j] == 0)
            return;

        if (i == m.size() - 1 && j == m[0].size() - 1)
        {
            v.push_back(s);
            // visited[i][j] = -1;
            return;
        }

        visited[i][j] = 1;

        dfs(i + 1, j, s + 'D', visited, v, m);
        dfs(i, j + 1, s + 'R', visited, v, m);
        dfs(i - 1, j, s + 'U', visited, v, m);
        dfs(i, j - 1, s + 'L', visited, v, m);

        visited[i][j] = -1;

        return;
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here

        vector<vector<int>> visited(m.size(), vector<int>(m[0].size(), -1));
        vector<string> v;

        // if(m[0][0]==0 || m[n-1][n-1]==0)
        //     return v;

        string s = "";

        dfs(0, 0, s, visited, v, m);

        sort(v.begin(), v.end());

        return v;
    }
};
