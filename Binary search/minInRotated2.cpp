class Solution
{
public:
    int findMin(vector<int> &arr)
    {

        int n = arr.size();

        if (arr[0] < arr[n - 1] || n == 1)
        {
            return arr[0];
        }

        int start = 0;
        int end = n - 1;

        while (start < end)
        {
            int mid = start + (end - start) / 2;

            if (arr[mid] > arr[end])
            {

                start = mid + 1;
            }

            else if (arr[mid] < arr[end])
            {
                end = mid;
            }
            else
                end--;
        }

        return arr[start];
    }
};