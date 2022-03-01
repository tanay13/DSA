#include <iostream>

using namespace std;

void selectionSort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {

        for (int j = i; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{

    int arr[7] = {4, 1, 6, 9, 10, 7, 11};

    selectionSort(arr, 7);

    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << '\n';

    return 0;
}