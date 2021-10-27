class Solution
{
public:
    bool canArrange(vector<int> &arr, int k)
    {

        vector<int> v;

        for (int i = 0; i < arr.size(); i++)
        {
            int a = (arr[i] % k + k) % k; // done to counter negative numbers
            v.push_back(a);
        }

        unordered_map<int, int> m;

        for (auto i : v)
        {
            m[i]++;
        }

        for (int i = 0; i < v.size(); i++)
        {

            if (v[i] == 0)
            {
                if (m[0] % 2 == 0)
                    continue;
                return false;
            }

            if (m[v[i]] == m[k - v[i]])
                continue;

            return false;
        }

        return true;
    }
};