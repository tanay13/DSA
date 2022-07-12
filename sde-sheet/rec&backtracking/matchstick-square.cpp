class Solution
{
public:
    bool func(vector<int> &m, vector<int> &sq, int i)
    {

        if (i > m.size() - 1)
        {
            if (sq[0] == 0 && sq[1] == 0 && sq[2] == 0 && sq[3] == 0)
                return true;
            return false;
        }

        for (int k = 0; k < 4; k++)
        {

            if (sq[k] - m[i] < 0)
                continue;

            sq[k] -= m[i];
            bool choose = func(m, sq, i + 1);
            sq[k] += m[i];
            if (choose)
            {
                return true;
            }
        }

        return false;
    }

    bool makesquare(vector<int> &m)
    {

        int sum = 0;

        for (auto it : m)
            sum += it;

        if (sum % 4 != 0)
            return false;

        vector<int> sq(4, sum / 4);

        sort(m.rbegin(), m.rend());

        return func(m, sq, 0);
    }
};