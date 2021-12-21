class Solution
{
public:
    int solve(int arr[], int i, int j, vector<vector<int>> &dp)
    {

        if (i >= j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        long long int ans = INT_MAX;

        for (int k = i; k < j; k++)
        {

            long long int temp = solve(arr, i, k, dp) + solve(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];

            ans = min(ans, temp);
        }

        dp[i][j] = ans;
        return dp[i][j];
    }

    int matrixMultiplication(int N, int arr[])
    {
        // code here

        vector<vector<int>> dp(101, vector<int>(101, -1));

        for (int i = 0; i < 101; i++)
            for (int j = 0; j < 101; j++)
                dp[i][j] = -1;

        return solve(arr, 1, N - 1, dp);
    }
};