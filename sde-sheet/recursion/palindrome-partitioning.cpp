class Solution
{
public:
    bool isPalindrome(string s)
    {

        for (int i = 0; i < s.length() / 2; i++)
        {
            if (s[i] == s[s.length() - i - 1])
                continue;
            else
                return false;
        }

        return true;
    }

    void rec(string s, int idx, vector<vector<string>> &ans, vector<string> &a)
    {

        if (idx == s.length())
        {
            ans.push_back(a);
            return;
        }

        for (int i = idx; i < s.length(); i++)
        {
            string x = s.substr(idx, i - idx + 1);

            if (isPalindrome(x))
            {
                a.push_back(x);
                rec(s, i + 1, ans, a);
                a.pop_back();
            }
        }

        return;
    }

    vector<vector<string>> partition(string s)
    {

        vector<vector<string>> ans;
        vector<string> a;

        rec(s, 0, ans, a);

        return ans;
    }
};