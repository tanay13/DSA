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
