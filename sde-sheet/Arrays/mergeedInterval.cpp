class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;

        int e = intervals[0][1];
        int s = intervals[0][0];

        for (int i = 1; i < intervals.size(); i++)
        {

            if (intervals[i][0] <= e)
            {
                e = max(e, intervals[i][1]);
            }
            else
            {
                vector<int> v;
                v.push_back(s);
                v.push_back(e);
                merged.push_back(v);
                s = intervals[i][0];
                e = intervals[i][1];
            }
        }

        vector<int> vec;
        vec.push_back(s);
        vec.push_back(e);
        merged.push_back(vec);

        return merged;
    }
};