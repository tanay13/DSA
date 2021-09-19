class Solution
{
public:
    string longestPalindrome(string s)
    {

        int n = s.length();

        int dp[n + 1][n + 1];

        for (int i = 0; i < n; i++)
            dp[i][i] = 1;

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
                if (s[i] == s[j] && dp[i + 1][j - 1] == 1)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
        }

        int max1 = INT_MIN;
        int start = 0;
        int end = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (dp[i][j] == 1)
                {
                    if (max1 < abs(i - j))
                    {
                        max1 = abs(i - j);
                        start = i;
                        end = j;
                    }
                }
            }
        }

        string s1 = "";

        for (int i = start; i < end + 1; i++)
        {
            s1 += s[i];
        }

        return s1;
    }
};