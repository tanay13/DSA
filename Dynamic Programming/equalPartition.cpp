class Solution
{
public:
    bool equalPartition(int N, int arr[])
    {
        // code here

        int dpSum;
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += arr[i];
        }
        if (sum % 2 != 0)
            return false;

        dpSum = sum / 2;
        bool subset[N + 1][dpSum + 1];
        for (int i = 0; i <= N; i++)
            subset[i][0] = true;

        for (int i = 1; i <= dpSum; i++)
            subset[0][i] = false;

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= dpSum; j++)
            {
                if (j < arr[i - 1])
                    subset[i][j] = subset[i - 1][j];
                if (j >= arr[i - 1])
                    subset[i][j] = subset[i - 1][j] || subset[i - 1][j - arr[i - 1]];
            }
        }

        return subset[N][dpSum];
    }
};