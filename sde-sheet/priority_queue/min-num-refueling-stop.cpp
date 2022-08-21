class Solution
{
public:
    static bool cmp(vector<int> &v1, vector<int> &v2)
    {
        return v1[0] < v2[0];
    }

    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {

        sort(stations.begin(), stations.end(), cmp);

        int i = 0, stop = 0;

        priority_queue<int> p;

        while (startFuel < target)
        {

            while (i < stations.size() && startFuel >= stations[i][0])
            {
                p.push(stations[i][1]);
                i++;
            }

            if (startFuel < target && p.size() > 0)
            {
                startFuel += p.top();
                p.pop();
                stop++;
            }
            else
            {
                return -1;
            }
        }

        return stop;
    }
};