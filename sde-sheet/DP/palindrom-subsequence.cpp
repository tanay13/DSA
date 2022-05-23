
class Solution
{
public:
    int countSubstrings(string s)
    {

        int n = s.length();

        int dp[n][n];

        if (n < 2)
        {
            return n;
        }

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
                dp[i][i + 1] = 1;
            else
                dp[i][i + 1] = 0;
        }

        for (int i = n - 3; i >= 0; i--)
        {
            for (int j = i + 2; j < n; j++)
            {
                if (s[j] == s[i] && dp[i + 1][j - 1] == 1)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (dp[i][j] == 1)
                    ans++;
            }
        }

        return ans;
    }
};