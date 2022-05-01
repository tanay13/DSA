class Solution
{
public:
    void dfs(int i, int j, vector<vector<char>> &grid, map<pair<int, int>, int> &m)
    {

        if (i > grid.size() - 1 || j > grid[0].size() - 1 || i < 0 || j < 0 || grid[i][j] == '0' || m[make_pair(i, j)] == 1)
            return;

        m[make_pair(i, j)] = 1;

        dfs(i - 1, j, grid, m);
        dfs(i, j - 1, grid, m);
        dfs(i + 1, j, grid, m);
        dfs(i, j + 1, grid, m);

        return;
    }

    int numIslands(vector<vector<char>> &grid)
    {

        map<pair<int, int>, int> m;

        int count = 0;

        for (int r = 0; r < grid.size(); r++)
        {
            for (int c = 0; c < grid[0].size(); c++)
            {
                if (m.find(make_pair(r, c)) == m.end() && grid[r][c] != '0')
                {
                    dfs(r, c, grid, m);
                    count++;
                }
            }
        }

        return count;
    }
};