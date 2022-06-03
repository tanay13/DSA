1. [Set matrix Zero](https://leetcode.com/problems/set-matrix-zeroes/)

   - check 1st row and column if they are going to be all zero
   - Except 1st row and column check the matrix and search for the zero
   - if a cell is zero assign the first row cell and column cell as zero and then process it in another loop accordingly

2. [Pascal Triangle](https://leetcode.com/problems/pascals-triangle/submissions/)

3. [Next permutaion](https://leetcode.com/problems/next-permutation/submissions/)

   - Find the breakpoint of increasing sequence
   - Again traverse from the back and find the first element greater than the breakpoint el.
   - swap them and reverse all the elements after the breakpoint index because from the back it will be linearly increasing
   - ![](../ss/np.png)

4. [Max subarray](https://leetcode.com/problems/maximum-subarray/)

   - sum = max(sum+nums[i],nums[i])
   - lsum = max(lsum,sum)

5. [Sort colors](https://leetcode.com/problems/sort-colors/submissions/)

   - Count # 0s,1s and 2s and then overwrite them into the array

6. [Best time to buy and Sell Stocks](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/)

7. [Rotate Matrix](https://leetcode.com/problems/rotate-image/)

   - Transpose the matrix and reverse each row

8. [Merged Intervals](https://leetcode.com/problems/merge-intervals/submissions/)

   - Sort the array on the basis of the first element
   - check if the interval's start date is less than or equal to the previous interval's end date
   - if it is, then make and interval of (s,max(currEnd,prevEnd))

9. [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/submissions/)

   - Start filling the num1 array from the end
   - initialize i = m-1 and j = n-1, k = m-n-1
   - compare the last el of both arrays and then put the greatest one in the kth position and then decrement k
   - if(nums1[i] < nums2[j])
     {
     nums1[k] = nums2[j];
     k--;
     j--;
     }
     else
     {
     nums1[k] = nums1[i];
     k--;
     i--;

     }

10. [Find Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/submissions/)

    - Put the elements to nums[nums[i]-1] positions
    - If nums[nums[i]-1] == nums[i] then this is the repeating number
    - if not equal then swap those elements and continue the algo without incrementing the index(i)

11. [Largest subarray with sum 0](https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1#)

    - First let us initialise a variable say sum = 0 which stores the sum of elements traversed so far and another variable say max = 0 which stores the length of longest subarray with sum zero.
    - Declare a HashMap<Integer, Integer> which stores the prefix sum of every element as key and its index as value.
    - Now traverse the array, and add the array element to our sum.
      (i) If sum = 0, then we can say that the subarray until the current index has a sum = 0, so we update max with the maximum value of (max, current_index+1)

12. [Range sum query](https://leetcode.com/problems/range-sum-query-2d-immutable/)

    - https://leetcode.com/problems/range-sum-query-2d-immutable/discuss/2104317/DP-Visualised-%2B-Interview-Tipss
