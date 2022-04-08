class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {

        vector<vector<double>> dp(101, vector<double>(101, 0));

        dp[0][0] = poured;

        for (int i = 1; i <= query_row; i++)
        {
            for (int j = 0; j < query_row; j++)
            {

                if (dp[i - 1][j] > 1)
                {
                    double s = dp[i - 1][j] - 1;
                    dp[i - 1][j] = 1;
                    dp[i][j] += s / 2;
                    dp[i][j + 1] += s / 2;
                }
            }
        }

        if (dp[query_row][query_glass] > 1)
            return 1;

        return dp[query_row][query_glass];
    }
};