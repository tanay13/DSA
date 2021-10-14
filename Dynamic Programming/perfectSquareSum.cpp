class Solution
{
public:
    long long ans(int n, vector<int> &sq, vector<int> &dp, int i, int sum)
    {

        if (i >= sq.size())
            return INT_MAX;

        if (sum < 0)
        {
            return INT_MAX;
        }

        if (sum == 0)
            return 0;

        if (dp[sum] != -1)
            return dp[sum];

        dp[sum] = min(1 + ans(n, sq, dp, i, sum - sq[i]), ans(n, sq, dp, i + 1, sum));

        return dp[sum];
    }

    int numSquares(int n)
    {

        vector<int> sq;

        for (int i = 1; i <= n; i++)
        {

            if (ceil(sqrt(i)) == floor(sqrt(i)))
                sq.push_back(i);
        }

        vector<int> dp(n + 1, -1);

        int a = ans(n, sq, dp, 0, n);

        return a;
    }
};