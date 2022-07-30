class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {

        vector<int> freq(27, 0);

        vector<string> ans;

        for (int i = 0; i < words2.size(); i++)
        {
            vector<int> v(27, 0);

            for (int j = 0; j < words2[i].size(); j++)
            {

                v[words2[i][j] - 97]++;
            }

            for (int i = 0; i < 27; i++)
            {
                freq[i] = max(freq[i], v[i]);
            }
        }

        for (int i = 0; i < words1.size(); i++)
        {

            vector<int> v(27, 0);

            for (int j = 0; j < words1[i].size(); j++)
            {

                v[words1[i][j] - 97]++;
            }

            bool f = true;

            for (int i = 0; i < 27; i++)
            {
                if (v[i] < freq[i])
                {
                    f = false;
                    break;
                }
            }

            if (f)
                ans.push_back(words1[i]);
        }

        return ans;
    }
};