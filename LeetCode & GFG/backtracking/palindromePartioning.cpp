class Solution
{
public:
    bool isPalindrome(string &s, int l, int r)
    {
        while (l < r)
        {
            if (s[l++] != s[r--])
            {
                return false;
            }
        }
        return true;
    }

    void solve(vector<vector<string>> &vec, string &str, int index, vector<string> &vc)
    {

        if (index == str.length())
        {
            vec.push_back(vc);
            return;
        }

        for (int i = index; i < str.length(); i++)
        {

            if (isPalindrome(str, index, i))
            {
                vc.push_back(str.substr(index, i - index + 1));
                solve(vec, str, i + 1, vc);
                vc.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {

        vector<vector<string>> vec;
        vector<string> vc;
        solve(vec, s, 0, vc);

        return vec;
    }
};