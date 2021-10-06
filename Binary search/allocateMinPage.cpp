class Solution
{
public:
    bool check(int A[], int M, int N, int barr)
    {

        int n = 1;
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            if (A[i] > barr)
                return false;

            sum += A[i];

            if (sum > barr)
            {
                sum = A[i];
                n++;

                if (n > M)
                    return false;
            }
        }

        return true;
    }

    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M)
    {
        //code here

        int start = A[0];
        int sum = 0;

        for (int i = 0; i < N; i++)
        {

            sum += A[i];
        }

        int end = sum;

        int res = -1;
        while (start <= end)
        {

            int mid = (end + start) / 2;

            if (check(A, M, N, mid))
            {
                res = mid;
                end = mid - 1;
            }
            else

            {
                start = mid + 1;
            }
        }

        return res;
    }
};