#include <iostream>

using namespace std;

void insertionSort(int arr[], int n)
{

    for (int i = 1; i < n - 1; i++)
    {

        int hole = i;
        int val = arr[i];
        while (hole > 0 && arr[hole - 1] > val)
        {
            arr[hole] = arr[hole - 1];
            hole--;
        }
        arr[hole] = val;
    }
}

int main()
{

    int arr[7] = {4, 1, 6, 9, 10, 7, 11};

    insertionSort(arr, 7);

    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << '\n';

    return 0;
}