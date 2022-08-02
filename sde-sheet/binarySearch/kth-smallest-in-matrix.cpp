class Solution
{
public:
    int kthSmallest(vector<vector<int>> &arr, int k)
    {

        int n = arr.size();

        int s = arr[0][0], e = arr[n - 1][n - 1];

        while (s < e)
        {
            int c = 0;

            int mid = s + (e - s) / 2;

            for (int i = 0; i < n; i++)
            {
                auto it = upper_bound(arr[i].begin(), arr[i].end(), mid) - arr[i].begin();

                c += it;
            }

            if (c < k)
            {
                s = mid + 1;
            }
            else
            {
                e = mid;
            }
        }

        return s;
    }
};