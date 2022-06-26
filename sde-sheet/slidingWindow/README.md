1. [Max points from cards](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/)

   - Let the sum of all points be total_pts. You need to remove a sub-array from cardPoints with length n - k.
   - Keep a window of size n - k over the array. The answer is max(answer, total_pts - sumOfCurrentWindow)
