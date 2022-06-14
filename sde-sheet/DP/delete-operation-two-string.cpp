class Solution
{
public:
    int lcs(vector<vector<int>> &dp, string w1, string w2, int i, int j)
    {

        if (i > w1.size() - 1 || j > w2.size() - 1)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (w1[i] == w2[j])
        {
            return dp[i][j] = 1 + lcs(dp, w1, w2, i + 1, j + 1);
        }

        return dp[i][j] = max(lcs(dp, w1, w2, i + 1, j), lcs(dp, w1, w2, i, j + 1));
    }

    int minDistance(string w1, string w2)
    {

        vector<vector<int>> dp(w1.size() + 1, vector<int>(w2.size() + 1, -1));

        int l = lcs(dp, w1, w2, 0, 0);
        int a = w1.size();
        int b = w2.size();
        int diff = abs(a - l) + abs(b - l);

        return diff;
    }
};