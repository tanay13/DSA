class Solution
{
public:
    int lengthOfLongestSubstring(string st)
    {

        map<char, int> m;

        if (st.length() == 0)
            return 0;

        int s = 0;
        int e = 0;

        int mxLen = 1;

        while (s <= e && e < st.length())
        {

            m[st[e]] = 1;

            if (m.size() == e - s + 1)
            {
                mxLen = max(mxLen, e - s + 1);
                e++;
                continue;
            }

            m.erase(st[s]);
            s++;
        }

        return mxLen;
    }
};