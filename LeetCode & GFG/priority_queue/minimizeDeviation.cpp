class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {

        priority_queue<int> pq;

        int mn = INT_MAX;
        int mx = INT_MIN;

        for (auto i : nums)
        {
            if (i % 2 != 0)
            {
                i *= 2;
            }
            mn = min(mn, i);
            mx = max(mx, i);
            pq.push(i);
        }

        int minD = mx - mn;

        while (pq.top() % 2 == 0)
        {
            int a = pq.top();
            pq.pop();

            minD = min(minD, a - mn);

            a = a / 2;

            mn = min(a, mn);

            pq.push(a);
        }

        minD = min(pq.top() - mn, minD);

        return minD;
    }
};