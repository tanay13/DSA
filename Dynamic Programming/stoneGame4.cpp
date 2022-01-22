class Solution
{
public:
    bool ans(int *dp, int n)
    {

        if (n == 0)
        {
            return false;
        }

        if (dp[n] != -1)
            return dp[n];

        bool win = false;

        for (int i = 1; i * i <= n; i++)
        {

            if (!ans(dp, n - i * i))
            {

                win = true;
                break;
            }
        }

        return dp[n] = win;
    }

    bool winnerSquareGame(int n)
    {

        int dp[100001];

        memset(dp, -1, sizeof(dp));

        return ans(dp, n);
    }
};