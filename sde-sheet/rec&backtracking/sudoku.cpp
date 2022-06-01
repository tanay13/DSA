class Solution
{
public:
    bool isPossible(char c, vector<vector<char>> &board, int i, int j)
    {

        for (int k = 0; k < 9; k++)
        {

            if (board[i][k] == c)
                return false;

            if (board[k][j] == c)
                return false;

            if (board[k / 3 + 3 * (i / 3)][k % 3 + 3 * (j / 3)] == c)
                return false;
        }
        return true;
    }

    bool backtrack(vector<vector<char>> &board, int i, int j)
    {
        if (i == 9)
            return true;

        if (j == 9)
            return backtrack(board, i + 1, 0);

        if (board[i][j] != '.')
            return backtrack(board, i, j + 1);

        for (char k = '1'; k <= '9'; k++)
        {
            if (isPossible(k, board, i, j))
            {
                board[i][j] = k;
                if (backtrack(board, i, j + 1))
                    return true;
                board[i][j] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>> &board)
    {

        backtrack(board, 0, 0);
        return;
    }
};