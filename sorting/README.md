## Insertion Sort

- We scan the whole array and find the smallest element
- Time complexity - O(n^2)

## Bubble sort

- At each scan we compare that element with the next element
- If the el is greater than the next el we swap them
- At each scan the largest element gets placed at right position
- Time Complexity - O(n^2)

## Insertion Sort

- Picking el from unsorted part and inserting it at the right place in the sorted part
- Holes are created at the current position and then previous els are compared and shifted to right accordingly
- Time complexity - O(n^2)

## Merge Sort

- We sort the two divided subarray and then merge both left subarray and right subarray and copy the values to the original array.
- Time complexity - O(nlogn)

## Quick Sort

- We choose the pivot element and place it in the array in such manner that all the left elements are smaller than it and all the elements to its right are bigger than the pivot element.
- Recursively applying partioning logic on both the subproblem
