1. [Search Suggestions system](https://leetcode.com/problems/search-suggestions-system/)

   - Loop through the search word
   - find the first and last occurrence of the character in the original vector
   - reduce the search space and repeat the steps

2. [Kth smallest in sorted matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/submissions/)

   - This can be solved using max heap also but to reduce the space complexity binary search is used.
   - taking l = arr[0][0] and r = arr[n-1][n-1] we find the mid element and then check at every row how many elements are smaller than the mid.
   - if count is less than k then it means that the mid valus should be increased therefore we increment the l variable to mid+1
