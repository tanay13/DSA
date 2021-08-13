// Question link - https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/614/week-2-august-8th-august-14th/3887/

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        unordered_map<int, map<char, int>> m;

        vector<vector<string>> s;

        vector<string> a;

        for (int i = 0; i < strs.size(); i++)
        {
            string s = "000000000000000000000000000";
            for (int j = 0; j < strs[i].length(); j++)
            {
                int index = (strs[i][j] & 31);
                char temp = s[index];
                int x = int(temp);
                x++;
                s[index] = char(x);
            }
            a.push_back(s);
        }

        vector<vector<string>> ans;
        vector<int> visited(strs.size(), 0);

        for (int i = 0; i < strs.size(); i++)
        {
            vector<string> str;
            if (visited[i] == 0)
            {
                str.push_back(strs[i]);
                visited[i] = 1;
            }

            for (int j = i; j < strs.size(); j++)
            {
                if (visited[j])
                    continue;
                if (a[i] == a[j])
                {
                    visited[j] = 1;
                    str.push_back(strs[j]);
                }
            }
            if (str.size() != 0)
                ans.push_back(str);
        }

        return ans;
    }
};