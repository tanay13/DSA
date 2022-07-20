class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {

        vector<vector<int>> v(26);

        for (int i = 0; i < s.length(); i++)
            v[s[i] - 'a'].push_back(i);

        sort(words.begin(), words.end());

        int ans = words.size();

        for (int i = 0; i < words.size(); i++)
        {
            int last = -1;

            for (int j = 0; j < words[i].size(); j++)
            {

                auto &it = v[words[i][j] - 'a'];

                auto idx = upper_bound(it.begin(), it.end(), last);

                if (idx == it.end())
                {
                    ans--;
                    break;
                }
                else
                {
                    last = *idx;
                }
            }
        }

        return ans;
    }
};