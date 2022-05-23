class Solution
{
public:
    float factorial(int n)
    {
        int f = 1;

        for (int i = 1; i <= n; i++)
        {
            f *= i;
        }
        return f;
    }

    string getPermutation(int n, int k)
    {

        vector<string> s;
        for (int i = 1; i <= n; i++)
        {
            s.push_back(to_string(i));
        }
        string ans = "";
        int r = n - 1;
        k--; // since a vector is stored in 0 based indexing
        while (true)
        {

            int factr = factorial(r);

            int idx = k / factr;

            ans += s[idx];

            s.erase(s.begin() + idx);

            if (r == 0)
                break;

            k = k % factr;

            r--;
        }

        return ans;
    }
};