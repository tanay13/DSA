class Solution
{
public:
    int maxLen(vector<int> &A, int n)
    {
        // Your code here

        map<int, int> m;
        int len = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += A[i];

            if (sum == 0)
            {
                len = i + 1;
            }
            else
            {
                if (m.find(sum) != m.end())
                {
                    len = max(len, i - m[sum]);
                }
                else
                {
                    m[sum] = i;
                }
            }
        }

        return len;
    }