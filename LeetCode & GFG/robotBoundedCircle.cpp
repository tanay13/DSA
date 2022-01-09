class Solution
{
public:
    bool isRobotBounded(string instructions)
    {

        char dir = 'N';

        int x = 0;
        int y = 0;

        for (int i = 0; i < instructions.length(); i++)
        {
            if (instructions[i] == 'G')
            {

                if (dir == 'N')
                {
                    y++;
                }
                else if (dir == 'W')
                {
                    x--;
                }
                else if (dir == 'E')
                {
                    x++;
                }
                else
                {
                    y--;
                }
            }
            else if (instructions[i] == 'L')
            {

                if (dir == 'N')
                    dir = 'W';
                else if (dir == 'W')
                    dir = 'S';
                else if (dir == 'E')
                    dir = 'N';
                else
                    dir = 'E';
            }
            else
            {

                if (dir == 'N')
                    dir = 'E';
                else if (dir == 'W')
                    dir = 'N';
                else if (dir == 'E')
                    dir = 'S';
                else
                    dir = 'W';
            }
        }

        if (x == 0 && y == 0)
            return true;
        else if ((x != 0 || y != 0) && dir != 'N')
            return true;
        else
            return false;
    }
};