class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {

        sort(intervals.begin(), intervals.end());

        int prevHigh = intervals[0][1];
        int prevLow = intervals[0][0];

        int c = 1;

        for (int i = 1; i < intervals.size(); i++)
        {

            if (prevHigh < intervals[i][1] && prevLow < intervals[i][0])
            {

                c++;
                prevLow = intervals[i][0];
            }

            prevHigh = max(intervals[i][1], prevHigh);
        }

        return c;
    }
};