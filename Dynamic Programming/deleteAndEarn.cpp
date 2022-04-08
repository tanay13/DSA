class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {

        map<int, int> m;

        for (auto i : nums)
            m[i]++;

        vector<int> vec;

        for (auto it : m)
            vec.push_back(it.first);

        sort(vec.begin(), vec.end());

        if (vec.size() < 2)
            return vec[0] * m[vec[0]];

        vector<int> dp(vec.size() + 1);

        dp[0] = vec[0] * m[vec[0]];

        if (vec[1] - vec[0] == 1)
        {
            dp[1] = max(dp[0], vec[1] * m[vec[1]]);
        }
        else
        {
            dp[1] = dp[0] + vec[1] * m[vec[1]];
        }

        for (int i = 2; i < vec.size(); i++)
        {

            if (vec[i] - vec[i - 1] == 1)
            {
                dp[i] = max(dp[i - 1], vec[i] * m[vec[i]] + dp[i - 2]);
            }
            else
            {
                dp[i] = dp[i - 1] + vec[i] * m[vec[i]];
            }
        }

        return dp[vec.size() - 1];
    }
};

// --------------------------------------------------------------------------------------------

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {

        map<int, int> m;

        for (auto i : nums)
            m[i]++;

        vector<int> vec;

        for (auto it : m)
            vec.push_back(it.first);

        sort(vec.begin(), vec.end());

        if (vec.size() < 2)
            return vec[0] * m[vec[0]];

        int e1 = 0, e2 = 0;

        for (int i = 0; i < vec.size(); i++)
        {

            if (i > 0 && vec[i] - vec[i - 1] == 1)
            {

                int temp = e2;

                e2 = max(e2, vec[i] * m[vec[i]] + e1);

                e1 = temp;
            }
            else
            {
                int temp = e2;

                e2 = vec[i] * m[vec[i]] + e2;

                e1 = temp;
            }
        }

        return e2;
    }
};