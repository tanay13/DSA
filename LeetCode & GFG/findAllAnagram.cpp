class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {

        vector<int> ph(26, 0);
        vector<int> sh(26, 0);

        vector<int> ans;

        if (s.length() < p.length())
            return ans;

        for (int i = 0; i < p.length(); i++)
            ph[p[i] - 'a']++;

        int st = 0;
        int l = p.length() - 1;

        for (int i = 0; i <= l; i++)
        {
            sh[s[i] - 'a']++;
        }

        while (l <= s.length() - 1)
        {

            if (ph == sh)
            {
                ans.push_back(st);
            }

            sh[s[st] - 'a']--;
            st++;
            l++;
            if (l < s.length())
                sh[s[l] - 'a']++;
            else
                break;
        }

        return ans;
    }
};