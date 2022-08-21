class Solution
{
public:
    bool isPossible(vector<int> &v)
    {

        map<int, int> m;

        map<int, int> l;

        // storing the freq of elements
        for (auto it : v)
            m[it]++;

        for (int i = 0; i < v.size(); i++)
        {
            // if freq is less than 1 then it can be a part of the subs
            if (m[v[i]] < 1)
                continue;

            if (l[v[i] - 1] > 0) // to check if v[i] can get atached to v[i]-1 to make a subsequence
            {
                m[v[i]]--;
                l[v[i] - 1]--;
                l[v[i]]++;
            }
            else if (m[v[i] + 1] > 0 && m[v[i]] > 0 && m[v[i] + 2] > 0) // checking if three consecutive numbers have freq greater than 0
            {
                m[v[i] + 1]--;
                m[v[i]]--;
                m[v[i] + 2]--;
                l[v[i] + 2]++; // increamenting the l[v[i]+2] value so that v[i]+3 can get attached to this if possible
            }
            else
                return false;
        }

        return true;
    }
};