#include <iostream>

using namespace std;

void merge(int leftSub[], int rightSub[], int arr[], int nL, int nR)
{

    int i = 0, j = 0, k = 0;
    while (i < nL && j < nR)
    {

        if (leftSub[i] <= rightSub[j])
        {
            arr[k] = leftSub[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = rightSub[j];
            j++;
            k++;
        }
    }

    while (i < nL)
    {
        arr[k] = leftSub[i];
        i++;
        k++;
    }
    while (j < nR)
    {
        arr[k] = rightSub[j];
        j++;
        k++;
    }
    return;
}

void mergeSort(int arr[], int n)
{

    if (n < 2)
        return;

    int mid = n / 2;

    int leftSub[mid];
    int rightSub[n - mid];

    for (int i = 0; i < mid; i++)
        leftSub[i] = arr[i];
    for (int i = mid; i < n; i++)
        rightSub[i - mid] = arr[i];

    mergeSort(leftSub, mid);
    mergeSort(rightSub, n - mid);
    merge(leftSub, rightSub, arr, mid, n - mid);

    return;
}

int main()
{

    int arr[7] = {4, 1, 6, 9, 10, 7, 11};

    mergeSort(arr, 2);

    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << '\n';

    return 0;
}