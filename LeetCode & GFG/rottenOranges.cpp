class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {

        queue<pair<int, int>> r;
        int mangoes = 0;

        if (grid.size() == 0)
            return 0;

        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 2)
                    r.push({i, j});

                if (grid[i][j] != 0)
                    mangoes++;
            }

        int dy[4] = {-1, 0, 1, 0};
        int dx[4] = {0, -1, 0, 1};

        int c = 0, time = 0;

        while (r.size() > 0)
        {
            int k = r.size();
            c += k;

            while (k--)
            {

                int x = r.front().first, y = r.front().second;
                r.pop();

                for (int i = 0; i < 4; i++)
                {
                    if (x + dx[i] < grid.size() && x + dx[i] >= 0 && y + dy[i] < grid[0].size() && y + dy[i] >= 0 && grid[x + dx[i]][y + dy[i]] == 1)
                    {
                        grid[x + dx[i]][y + dy[i]] = 2;
                        r.push({x + dx[i], y + dy[i]});
                    }
                }
            }

            if (!r.empty())
                time++;
        }

        cout << c << " " << mangoes;

        if (c == mangoes)
            return time;
        return -1;
    }
};