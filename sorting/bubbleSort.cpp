#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n - i - 1; j++)
        {
            bool flag = false;
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                flag = true;
            }
        }
        if (!flag)
            break;
    }
}

int main()
{

    int arr[7] = {4, 1, 6, 9, 10, 7, 11};

    bubbleSort(arr, 7);

    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << '\n';

    return 0;
}