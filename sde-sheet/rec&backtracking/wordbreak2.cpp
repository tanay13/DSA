class Solution
{
public:
    void func(string s, map<string, int> &m, int prev, int curr, string str, vector<string> &ans)
    {

        if (curr == s.length())
        {
            ans.push_back(str);
            return;
        }

        if (str.length() > 0)
            str += " ";

        for (int i = curr; i < s.length(); i++)
        {

            string temp = s.substr(prev, i - prev + 1);

            if (m.find(temp) != m.end())
            {
                func(s, m, i + 1, i + 1, str + temp, ans);
            }
        }

        return;
    }

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {

        vector<string> ans;

        string str = "";

        map<string, int> m;

        for (auto it : wordDict)
            m[it] = 1;

        func(s, m, 0, 0, str, ans);

        return ans;
    }
};