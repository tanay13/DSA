class Solution
{
public:
    void dfs(vector<vector<char>> &board, map<pair<int, int>, int> &v, int i, int j)
    {

        if (i > board.size() - 1 || i < 0 || j > board[0].size() - 1 || j < 0 || v[{i, j}] == 1 || board[i][j] == 'X')
            return;

        v[{i, j}] = 1;
        board[i][j] = 'A';

        dfs(board, v, i + 1, j);
        dfs(board, v, i, j + 1);
        dfs(board, v, i - 1, j);
        dfs(board, v, i, j - 1);
    }

    void solve(vector<vector<char>> &board)
    {

        int m = board.size();
        int n = board[0].size();

        map<pair<int, int>, int> v;

        for (int i = 0; i < n; i++)
        {
            if (board[0][i] == 'O' && v.find({0, i}) == v.end())
            {
                dfs(board, v, 0, i);
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O' && v.find({i, 0}) == v.end())
            {
                dfs(board, v, i, 0);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (board[m - 1][i] == 'O' && v.find({m - 1, i}) == v.end())
            {
                dfs(board, v, m - 1, i);
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (board[i][n - 1] == 'O' && v.find({i, n - 1}) == v.end())
            {
                dfs(board, v, i, n - 1);
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == 'A')
                    board[i][j] = 'O';
            }
        }
    }
};