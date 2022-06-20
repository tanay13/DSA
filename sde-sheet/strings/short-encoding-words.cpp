class Solution
{
public:
    bool static cmp(string s1, string s2)
    {
        return s1.length() > s2.length();
    }

    int minimumLengthEncoding(vector<string> &words)
    {

        map<string, int> m;
        map<string, int> m1;
        sort(words.begin(), words.end(), cmp);

        for (string st : words)
            m1[st] = 1;

        int ans = 0;

        for (int i = 0; i < words.size(); i++)
        {
            bool f = false;
            for (int j = 0; j < words[i].length(); j++)
            {
                string s = words[i].substr(j, words[i].length() - j);
                if (m1.find(s) != m1.end())
                {
                    f = true;
                    m1.erase(s);
                }
            }
            if (f)
                ans += words[i].length() + 1;
        }

        return ans;
    }
};
