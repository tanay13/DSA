class Solution
{
public:
    int maxArea(int hr, int wd, vector<int> &h, vector<int> &c)
    {

        sort(h.begin(), h.end());
        sort(c.begin(), c.end());

        long long mod = 1e9 + 7;

        long long mxW = h[0], mxL = c[0], diff;

        for (int i = 1; i < h.size(); i++)
        {
            diff = h[i] - h[i - 1];
            mxW = max(mxW, diff);
        }
        diff = hr - h[h.size() - 1];
        mxW = max(mxW, diff);

        for (int i = 1; i < c.size(); i++)
        {
            diff = c[i] - c[i - 1];
            mxL = max(mxL, diff);
        }
        diff = wd - c[c.size() - 1];
        mxL = max(mxL, diff);

        return (mxW * mxL) % mod;
    }
};