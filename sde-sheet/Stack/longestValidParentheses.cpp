class Solution
{
public:
    int longestValidParentheses(string s)
    {

        stack<pair<char, int>> st;

        if (s.length() == 0 || s.length() == 1)
            return 0;

        st.push(make_pair(s[0], 0));

        for (int i = 1; i < s.length(); i++)
        {
            if (st.size() > 0)
            {
                auto c = st.top().first;

                if (c == '(' && s[i] == ')')
                {
                    st.pop();
                    continue;
                }
            }

            st.push(make_pair(s[i], i));
        }

        vector<int> v;

        if (st.empty())
            return s.length();

        while (!st.empty())
        {
            int i = st.top().second;
            st.pop();
            cout << i << " ";
            v.push_back(i);
        }

        int mx = v[v.size() - 1];

        for (int i = v.size() - 1; i >= 1; i--)
        {
            mx = max(mx, v[i - 1] - v[i] - 1);
        }

        int x = s.length() - v[0] - 1;

        mx = max(mx, x);

        return mx;
    }
};