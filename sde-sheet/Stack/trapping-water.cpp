class Solution
{
public:
    int trap(vector<int> &h)
    {

        int n = h.size();

        vector<int> lh(n), rh(n);

        lh[0] = h[0];
        for (int i = 1; i < n; i++)
        {
            lh[i] = max(h[i], lh[i - 1]);
        }
        rh[n - 1] = h[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            rh[i] = max(h[i], rh[i + 1]);
        }

        int a = 0;

        for (int i = 0; i < n; i++)
        {

            int ht = min(lh[i], rh[i]);

            a += (ht - h[i]);
        }

        return a;
    }
};