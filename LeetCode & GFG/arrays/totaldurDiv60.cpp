class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {

        int n = time.size();

        int rem[61] = {0};

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            int t = time[i] % 60;

            count = count + rem[(60 - t) % 60];

            rem[t]++;
        }

        return count;
    }
};