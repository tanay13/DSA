class Solution
{
public:
    int func(string a, string b, int i, int j, vector<vector<int>> &dp)
    {

        if (i < 0 || j < 0)
        {
            if (i == 0 && j == 0)
                return 0;

            if (i < 0)
                return j + 1;
            if (j < 0)
                return i + 1;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (a[i] == b[j])
        {
            return dp[i][j] = func(a, b, i - 1, j - 1, dp);
        }

        int t = func(a, b, i - 1, j, dp);
        int t1 = func(a, b, i, j - 1, dp);
        int t2 = func(a, b, i - 1, j - 1, dp);

        int mx = min(t, t1);
        int mn = min(mx, t2);

        return dp[i][j] = 1 + mn;
    }

    int minDistance(string word1, string word2)
    {

        int dp[word1.length() + 1][word2.length() + 1];

        for (int i = 0; i < word1.length() + 1; i++)
        {

            for (int j = 0; j < word2.length() + 1; j++)
            {

                if (i == 0)
                {
                    dp[i][j] = j;
                    continue;
                }
                if (j == 0)
                {
                    dp[i][j] = i;
                    continue;
                }

                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                    continue;
                }

                int t = min(dp[i][j - 1], dp[i - 1][j]); // insert and delete

                dp[i][j] = 1 + min(dp[i - 1][j - 1], t); // min of insert, delete and replace
            }
        }

        return dp[word1.length()][word2.length()];
    }
};