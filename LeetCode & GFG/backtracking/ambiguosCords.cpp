class Solution
{
public:
    vector<string> getCord(string s)
    {

        vector<string> res;

        if (s.length() == 1)
            return {s};

        if (s[0] == '0')
        {
            if (s.back() == '0')
                return {};
            return {"0." + s.substr(1)};
        }

        if (s[0] != '0')
        {

            res.push_back(s);
        }

        for (int i = 1; i < s.length(); i++)
        {
            if (s.substr(i).back() == '0')
                continue;
            res.push_back(s.substr(0, i) + "." + s.substr(i));
        }

        return res;
    }

    vector<string> ambiguousCoordinates(string s)
    {

        vector<string> vec;

        string s1 = s.substr(1, s.size() - 2);

        int n = s1.size();

        for (int i = 1; i < n; i++)
        {

            vector<string> f = getCord(s1.substr(0, i));
            vector<string> sec = getCord(s1.substr(i));

            for (auto it : f)
            {

                for (auto j : sec)
                {
                    vec.push_back("(" + it + "," + " " + j + ")");
                }
            }
        }

        return vec;
    }
};