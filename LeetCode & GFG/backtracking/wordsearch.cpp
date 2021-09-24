class Solution
{
public:
    bool backtrack(vector<vector<int>> &v, vector<vector<char>> &board, string word, int i, int r, int c)
    {

        if (i == word.length())
            return true;

        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || v[r][c] != -1 || board[r][c] != word[i])
            return false;

        v[r][c] = 1;

        int ans = backtrack(v, board, word, i + 1, r + 1, c) || backtrack(v, board, word, i + 1, r, c + 1) || backtrack(v, board, word, i + 1, r - 1, c) || backtrack(v, board, word, i + 1, r, c - 1);

        v[r][c] = -1;

        return ans;
    }

    bool exist(vector<vector<char>> &board, string word)
    {

        for (int i = 0; i < board.size(); i++)
        {

            for (int j = 0; j < board[0].size(); j++)
            {
                vector<vector<int>> v(board.size() + 1, vector<int>(board[0].size() + 1, -1));

                if (backtrack(v, board, word, 0, i, j))
                    return true;
            }
        }

        return false;
    }
};