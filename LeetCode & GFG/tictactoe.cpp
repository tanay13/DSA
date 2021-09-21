class Solution
{
public:
    bool isWinner(vector<vector<int>> &moves, int player)
    {

        int cross[3][3];

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cross[i][j] = 0;

        for (int i = player; i < moves.size(); i += 2)
        {
            cross[moves[i][0]][moves[i][1]] = 1;
        }

        if (cross[0][0] == 1 && cross[0][1] == 1 && cross[0][2] == 1)
            return true;
        if (cross[1][0] == 1 && cross[1][1] == 1 && cross[1][2] == 1)
            return true;
        if (cross[2][0] == 1 && cross[2][1] == 1 && cross[2][2] == 1)
            return true;
        if (cross[0][0] == 1 && cross[1][0] == 1 && cross[2][0] == 1)
            return true;
        if (cross[0][1] == 1 && cross[1][1] == 1 && cross[2][1] == 1)
            return true;
        if (cross[0][2] == 1 && cross[1][2] == 1 && cross[2][2] == 1)
            return true;
        if (cross[0][0] == 1 && cross[1][1] == 1 && cross[2][2] == 1)
            return true;
        if (cross[0][2] == 1 && cross[1][1] == 1 && cross[2][0] == 1)
            return true;

        cout << player;
        return false;
    }

    string tictactoe(vector<vector<int>> &moves)
    {

        if (isWinner(moves, 0))
        {
            return "A";
        }
        if (isWinner(moves, 1))
        {
            return "B";
        }

        if (moves.size() == 9)
            return "Draw";
        else
            return "Pending";
    }
};