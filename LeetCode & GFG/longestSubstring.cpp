class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        if (s.length() == 0)
            return 0;

        unordered_map<char, int> u;
        int i = 0;
        int j = 0;
        int ans = 1;
        u[s[i]]++;
        while (j != s.length() - 1)
        {
            if (u.find(s[j + 1]) == u.end())
            {
                j++;
                u[s[j]] = 1;
                ans = max(ans, j - i + 1);
            }
            else
            {
                u[s[i]]--;
                if (u[s[i]] == 0)
                    u.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};