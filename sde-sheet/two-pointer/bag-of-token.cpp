class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {

        sort(tokens.begin(), tokens.end());

        int s = 0;

        int a = 0;
        int b = tokens.size() - 1;

        int r = 0;

        while (a <= b)
        {
            if (power >= tokens[a])
            {
                power -= tokens[a];
                a++;
                r = max(r, ++s);
            }
            else if (s >= 1)
            {
                power += tokens[b];
                s--;
                b--;
            }
            else
            {
                break;
            }
        }

        return r;
    }
};