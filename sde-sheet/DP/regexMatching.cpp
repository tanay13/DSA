class Solution
{
public:
    bool rec(string s, string p, int i, int j, vector<vector<int>> &dp)
    {

        if (dp[i][j] != -1)
            return dp[i][j];

        if (i >= s.length() && j >= p.length())
            return true;

        if (j >= p.length())
            return false;

        bool match = (i < s.length() && ((s[i] == p[j]) || (p[j] == '.')));

        if (j + 1 < p.length() && p[j + 1] == '*')
        {

            return dp[i][j] = (match && rec(s, p, i + 1, j, dp)) || rec(s, p, i, j + 2, dp);
        }

        if (match)
            return dp[i][j] = rec(s, p, i + 1, j + 1, dp);

        return false;
    }

    bool isMatch(string s, string p)
    {

        vector<vector<int>> dp(s.length() + 2, vector<int>(p.length() + 2, -1));

        return rec(s, p, 0, 0, dp);
    }
};