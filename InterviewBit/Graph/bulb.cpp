int Solution::bulbs(vector<int> &A)
{

    int s = 0;

    for (int i = 0; i < A.size(); i++)
    {

        if (s % 2 != 0)
        {
            if (A[i] == 0)
                A[i] = 1;
            else
                A[i] = 0;
        }

        if (A[i] == 0)
        {
            s++;
        }
    }

    return s;
}
