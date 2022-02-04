class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {

        map<int, int> m;

        int sum = 0;
        int start = 0;
        int len = 0;

        for (int i = 0; i < nums.size(); i++)
        {

            if (nums[i] == 0)
                sum -= 1;
            else
                sum += 1;

            if (sum == 0)
            {
                len = max(len, i + 1);
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
};