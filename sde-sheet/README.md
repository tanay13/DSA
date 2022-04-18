1. [Set matrix Zero](https://leetcode.com/problems/set-matrix-zeroes/)

   - check 1st row and column if they are going to be all zero
   - Except 1st row and column check the matrix and search for the zero
   - if a cell is zero assign the first row cell and column cell as zero and then process it in another loop accordingly

2. [Pascal Triangle](https://leetcode.com/problems/pascals-triangle/submissions/)

3. [Next permutaion](https://leetcode.com/problems/next-permutation/submissions/)

   - Find the breakpoint of increasing sequence
   - Again traverse from the back and find the first element greater than the breakpoint el.
   - swap them and reverse all the elements after the breakpoint index because from the back it will be linearly increasing
   - ![](ss/np.png)

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
