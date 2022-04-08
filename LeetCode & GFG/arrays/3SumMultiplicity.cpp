class Solution
{
public:
    int threeSumMulti(vector<int> &arr, int target)
    {

        map<int, long> m;

        for (auto i : arr)
            m[i]++;

        long ans = 0;

        for (auto it : m)
        {
            for (auto it1 : m)
            {
                int i = it.first;
                int j = it1.first;

                int k = target - (i + j);

                if (m.find(k) != m.end())
                {

                    long f1 = it.second;
                    long f2 = it1.second;
                    long f3 = m[k];

                    if (i == j && j == k)
                    {
                        ans += ((f1) * (f1 - 1) * (f1 - 2) / 6);
                    }
                    else if (i == j && j != k)
                    {
                        ans += ((f3) * ((f1) * (f1 - 1) / 2));
                    }
                    else if (i < j && j < k)
                    {
                        ans += (f1 * f2 * f3);
                    }
                }
            }
        }

        return ans % (int)(1e9 + 7);
    }
};