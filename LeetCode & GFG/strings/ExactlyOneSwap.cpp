class Solution
{
public:
    long long countStrings(string S)
    {
        // code here
        vector<long long> v(27, 0);

        for (auto it : S)
        {
            v[it - 'a']++;
        }

        long long c = 0;
        bool f = false;
        for (int i = 0; i < S.length(); i++)
        {

            if (v[S[i] - 'a'] < 2)
            {
                c += (S.length() - i - 1);
            }
            else if (v[S[i] - 'a'] >= 2 && f == false)
            {
                c += ((S.length() - i - 1) - (v[S[i] - 'a'] - 2));
                f = true;
            }
            else if (v[S[i] - 'a'] >= 2 && f)
            {
                c += ((S.length() - i - 1) - (v[S[i] - 'a'] - 1));
            }

            v[S[i] - 'a']--;
        }

        return c;
    }
};