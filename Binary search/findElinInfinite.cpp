
// Searching element in an infinite sorted array.
// doubling the size of the window if aarr[end] < target

void search(int arr[], int target)
{

    int start = 0;
    int end = 1;

    if (target > arr[end])
    {
        int temp = end + 1;

        end = end + (end - start + 1) * 2;

        start = temp;
    }

    return binSearch(arr, start, end);
}
