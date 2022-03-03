#include <iostream>

using namespace std;

int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int pivotIndex = start;

    // till end-1 because the last element can be the biggest element
    for (int i = start; i < end; i++)
    {

        if (arr[i] <= pivot)
        {
            int t = arr[i];
            arr[i] = arr[pivotIndex];
            arr[pivotIndex] = t;
            pivotIndex++;
        }
    }

    int t = arr[end];
    arr[end] = arr[pivotIndex];
    arr[pivotIndex] = t;

    return pivotIndex;
}

int randomizedPartition(int arr[], int start, int end)
{

    int pIdx = rand() % (end - start + 1) + start;
    int t = arr[end];
    arr[end] = arr[pIdx];
    arr[pIdx] = t;
    return partition(arr, start, end);
}

void quickSort(int arr[], int start, int end)
{

    if (start >= end)
        return;

    int pivotIndex = randomizedPartition(arr, start, end);

    quickSort(arr, start, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, end);

    return;
}

int main()
{

    int arr[7] = {4, 1, 6, 9, 10, 7, 11};

    quickSort(arr, 0, 6);

    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << '\n';

    return 0;
}