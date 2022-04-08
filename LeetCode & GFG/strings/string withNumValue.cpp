class Solution
{
public:
    string getSmallestString(int n, int k)
    {

        string s = "";

        for (int i = 0; i < n; i++)
        {
            s += 'a';
            k--;
        }
        int ind = n - 1;

        while (k > 0)
        {

            int m = min(k, 25);
            s[ind] += m;
            k -= m;
            ind--;
        }
        return s;
    }
};