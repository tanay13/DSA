class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {

        vector<int> v1(26, 0);
        vector<int> v2(26, 0);

        if (s1.length() > s2.length())
            return false;

        for (int i = 0; i < s1.length(); i++)
            v1[s1[i] - 'a']++;

        int s = 0;
        for (int i = 0; i < s2.length(); i++)
        {

            v2[s2[i] - 'a']++;

            if ((i - s) > s1.length() - 1)
            {

                v2[s2[s] - 'a']--;
                s++;
            }

            if (v1 == v2)
                return true;
        }

        return false;
    }
};