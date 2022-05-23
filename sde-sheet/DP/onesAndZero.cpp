class Solution
{
public:
    int dp[601][101][101];
    int ans(vector<pair<int, int>> &vp, int i, int m, int n)
    {

        if (m < 0 || n < 0)
            return -1;

        if (i > vp.size() - 1)
            return 0;

        if (dp[i][m][n] != -1)
            return dp[i][m][n];

        int o = vp[i].first;
        int z = vp[i].second;

        dp[i][m][n] = max(1 + ans(vp, i + 1, m - z, n - o), ans(vp, i + 1, m, n));

        return dp[i][m][n];
    }

    int findMaxForm(vector<string> &strs, int m, int n)
    {

        vector<pair<int, int>> vp;

        for (int i = 0; i < strs.size(); i++)
        {
            int o = 0;
            int z = 0;

            for (int j = 0; j < strs[i].size(); j++)
            {

                if (strs[i][j] == '0')
                    z++;
                else
                    o++;
            }

            vp.push_back(make_pair(o, z));
        }

        memset(dp, -1, sizeof(dp));
        return ans(vp, 0, m, n);
    }
};