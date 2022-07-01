#include <vector>

int findNumberOfLIS(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();

    vector<int> dp(n + 1, 1), c(n + 1, 1);
    int mx = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                c[i] = c[j];
            }
            else if (arr[i] > arr[j] && dp[j] + 1 == dp[i])
            {
                c[i] += c[j];
            }
        }
        mx = max(dp[i], mx);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == mx)
            ans += c[i];
    }

    return ans;
}