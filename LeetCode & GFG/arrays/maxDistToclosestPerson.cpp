class Solution
{
public:
    int maxDistToClosest(vector<int> &seats)
    {

        vector<int> occ;

        for (int i = 0; i < seats.size(); i++)
        {
            if (seats[i] == 1)
                occ.push_back(i);
        }
        int a = seats.size() - 1 - occ[occ.size() - 1];
        int ans = max(occ[0], a);
        int res = INT_MAX;

        int s = 0;
        int e = 1;

        int n = occ.size();

        while (s < n && e < n)
        {

            int mid = (occ[e] + occ[s]) / 2;

            res = min(mid - occ[s], occ[e] - mid);

            ans = max(ans, res);

            s++;
            e++;
        }

        return ans;
    }
};