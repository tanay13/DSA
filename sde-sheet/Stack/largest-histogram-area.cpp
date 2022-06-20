class Solution
{
public:
    int largestRectangleArea(vector<int> &h)
    {

        vector<int> lf(h.size()), rg(h.size());

        stack<int> s;

        int i = h.size() - 1;

        while (i >= 0)
        {
            while (s.size() > 0 && h[s.top()] >= h[i])
            {
                s.pop();
            }

            if (s.size() == 0)
            {
                rg[i] = h.size() - 1;
            }
            else
            {
                int idx = s.top() - 1;
                rg[i] = idx;
            }

            s.push(i);
            i--;
        }
        i = 0;

        stack<int> q;

        i = 0;

        while (i < h.size())
        {
            while (q.size() > 0 && h[q.top()] >= h[i])
            {
                q.pop();
            }

            if (q.size() == 0)
            {
                lf[i] = 0;
            }
            else
            {
                int idx = q.top() + 1;
                lf[i] = idx;
            }

            q.push(i);
            i++;
        }

        long long mxarea = INT_MIN;

        for (int i = 0; i < h.size(); i++)
        {
            long long len = rg[i] - lf[i] + 1;
            mxarea = max(mxarea, h[i] * len);
        }
        return mxarea;
    }
};