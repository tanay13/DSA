class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {

        if (nums.size() == 0)
            return 0;

        map<int, int> m;

        for (auto it : nums)
            m[it] = 1;

        int prev = INT_MIN, ans = 1, finAns = 1;

        for (auto it : m)
        {

            if (prev != INT_MIN && prev + 1 == it.first)
            {
                prev = it.first;
                ans++;
            }
            else
            {

                ans = 1;
                prev = it.first;
            }
            finAns = max(finAns, ans);
        }

        return finAns;
    }
};