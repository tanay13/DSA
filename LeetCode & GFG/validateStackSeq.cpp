class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {

        stack<int> st;

        int n = pushed.size() - 1;

        st.push(pushed[0]);

        int i = 1, j = 0;

        while (i <= n + 1 && j <= n)
        {

            if (j <= n && st.size() > 0 && st.top() == popped[j])
            {
                st.pop();
                j++;
                continue;
            }

            if (i <= n)
            {

                st.push(pushed[i]);
            }

            i++;
        }

        if (st.empty())
            return true;
        return false;
    }
};