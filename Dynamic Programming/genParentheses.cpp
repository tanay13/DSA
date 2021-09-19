class Solution
{
public:
    void construct(string s, int o, int c, int n, vector<string> &v)
    {
        if (o == c && o == n)
        {
            v.push_back(s);
            return;
        }

        if (o < n)
        {

            construct(s + "(", o + 1, c, n, v);
        }

        if (c < o)
        {

            construct(s + ")", o, c + 1, n, v);
        }

        return;
    }

    vector<string> generateParenthesis(int n)
    {

        vector<string> vec;
        string s = "";

        construct(s, 0, 0, n, vec);

        return vec;
    }
};