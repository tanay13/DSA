class Solution
{

public:
    int maxTwoEvents(vector<vector<int>> &events)
    {

        sort(events.begin(), events.end(), [](vector<int> &a, vector<int> &b)
             {
                 if (a[0] == b[0])
                     return a[1] < b[1];
                 return a[0] < b[0];
             });

        vector<int> v(events.size());

        v[events.size() - 1] = events[events.size() - 1][2];

        for (int i = events.size() - 2; i >= 0; i--)
        {

            v[i] = max(v[i + 1], events[i][2]);
        }

        int ans = 0;

        for (int i = 0; i < events.size(); i++)
        {

            int s = i + 1;
            int e = events.size() - 1;
            int p = -1;

            while (s <= e)
            {

                int mid = s + (e - s) / 2;

                if (events[mid][0] > events[i][1])
                {
                    p = mid;
                    e = mid - 1;
                    continue;
                }

                if (events[mid][0] <= events[i][1])
                {
                    s = mid + 1;
                }
            }
            if (p != -1)
                ans = max(ans, events[i][2] + v[p]);

            ans = max(ans, events[i][2]);
        }

        return ans;
    }
};