1. [Longest Valid parentheses](https://leetcode.com/problems/longest-valid-parentheses/submissions/)

   - pushing all the chars in the stack and popping all the balanced pair
   - so at the end only the unbalanced chars will be left
   - max length can be found by calculating the lenght between two unbalanced chars

2. [Next Greater element](https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1/#)

   - Storing the elements from the back of vector in the stack (to store all the elements to the right of the current index)
   - if the stack is empty then push -1 in the result vector since there is no element greater than the current element in the right side
   - popping the stack element until the top element is greater than the current element.

3. [Stock Span]()

   - Find the index of the next greater element to the left of the ith element and then push the difference in the index in the result vector

4. [Largest rectangle in histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/)

   - Find NSL and NSR index for all the indices
   - find the max area considering the nsl and nsr index
