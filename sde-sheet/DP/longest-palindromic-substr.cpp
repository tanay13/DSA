class Solution
{
public:
    string longestPalindrome(string s)
    {

        int n = s.length();

        int dp[n + 1][n + 1];

        int mI = 0, mJ = 0;

        for (int i = 0; i < n; i++)
            dp[i][i] = 1;

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = 1;
                mI = i;
                mJ = i + 1;
            }

            else
                dp[i][i + 1] = 0;
        }

        int mxLen = INT_MIN;

        for (int i = n - 3; i >= 0; i--)
        {
            for (int j = i + 2; j < n; j++)
            {

                if (s[i] == s[j] && dp[i + 1][j - 1] == 1)
                {
                    dp[i][j] = 1;

                    if (mxLen < j - i + 1)
                    {
                        mxLen = j - i + 1;
                        mI = i;
                        mJ = j;
                    }
                }
                else
                    dp[i][j] = 0;
            }
        }

        return s.substr(mI, mJ - mI + 1);
    }
};