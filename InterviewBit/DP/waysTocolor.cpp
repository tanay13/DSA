#define mod 1000000007

int isCompatible(vector<vector<int>> &pos, int j, int i)
{

    if (pos[i][0] == pos[j][0] || pos[i][1] == pos[j][1] || pos[i][2] == pos[j][2])
        return 0;

    return 1;
}

int Solution::solve(int A)
{

    vector<vector<int>> pos;

    for (int i = 0; i < 4; i++)
    {

        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                vector<int> a;
                if (i != j && j != k)
                {
                    a.push_back(i);
                    a.push_back(j);
                    a.push_back(k);
                    pos.push_back(a);
                }
            }
        }
    }

    int dp[38][100005];

    for (int i = 0; i < A; i++)
    {
        for (int j = 0; j < 36; j++)
        {

            if (i == 0)
            {
                dp[j][i] = 1;
            }
            else
            {
                long long temp = 0;

                for (int k = 0; k < 36; k++)
                {
                    if (isCompatible(pos, j, k))
                    {
                        temp += dp[k][i - 1];
                        temp = temp % mod;
                    }
                }

                dp[j][i] = temp;
            }
        }
    }

    long long ans = 0;

    for (int i = 0; i < pos.size(); i++)
    {
        ans = (ans + dp[i][A - 1]) % mod;
    }

    return ans;
}
