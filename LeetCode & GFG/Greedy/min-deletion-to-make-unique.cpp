class Solution
{
public:
    int minDeletions(string s)
    {

        vector<int> vec(26, 0);

        for (auto it : s)
        {
            vec[it - 'a']++;
        }

        sort(vec.rbegin(), vec.rend());

        int f = vec[0];

        int ans = 0;

        for (int it : vec)
        {

            if (it > f)
            {

                if (f > 0)
                    ans += (it - f);
                else
                    ans += it;
            }

            f = min(f - 1, it - 1);
        }

        return ans;
    }
};