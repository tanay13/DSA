class Solution
{
public:
    vector<int> countBits(int n)
    {

        vector<int> ans(n + 1);

        ans[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            int a = i / 2;
            if (i % 2 == 0)
            {

                ans[i] = ans[a];
            }
            else
            {
                ans[i] = ans[a] + 1;
            }
        }

        return ans;
    }
};