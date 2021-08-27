int Solution::solve(vector<int> &A, int B)
{

    int sum = 0;

    for (int i = 0; i < B; i++)
    {
        sum += A[i];
    }
    int result = sum;
    for (int i = 0; i < B; i++)
    {
        sum -= A[B - i - 1];
        sum += A[A.size() - 1 - i];

        result = max(sum, result);
    }
    return result;
}
