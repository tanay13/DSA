class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {

        sort(piles.begin(), piles.end());

        if (h == piles.size())
            return piles[piles.size() - 1];

        int low = 1;
        int high = piles[piles.size() - 1];

        int hours;

        while (low <= high)
        {

            int mid = low + (high - low) / 2;

            hours = 0;

            for (int i = 0; i < piles.size(); i++)
            {
                hours += ceil(1.0 * piles[i] / mid);
            }

            if (hours == h)
            {

                high = mid - 1;
                continue;
            }

            if (hours > h)
            {

                low = mid + 1;
                continue;
            }

            if (hours < h)
            {

                high = mid - 1;
                continue;
            }
        }

        return low;
    }
};