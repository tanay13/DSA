int findPlatform(int arr[], int dep[], int n)
{
    // Your code here

    sort(arr, arr + n);
    sort(dep, dep + n);

    int a = 1;
    int d = 0;
    int s = 1;
    int res = INT_MIN;

    while (a < n && d < n)
    {

        if (arr[a] > dep[d])
        {
            d++;
            s--;
        }
        else
        {

            s++;
            a++;
        }

        res = max(res, s);
    }

    return res;
}