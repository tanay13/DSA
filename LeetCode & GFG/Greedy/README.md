1. [Gas station]()

   - Init need and left_gas variable.
   - need will keep count of how many extra gas is required to reach to the current index from the starting.
   - if we reach till the end of the array and we find that left_gas < need then it means that we are not able to collect the extra gas required to complete the circuit from any of the index. So we return -1

2. [Min deletion to make](https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/)

   - store the freq of all letters in a vector
   - sort it in descending order
   - init f = v[0];
   - iterate through the vector
   - if the freq is greater than f then remove the (it-f) occurrences of the current letter(if f>0)
   - if f <= 0 it means that all the letters should be deleted.

3. [Queue Reconstruction](https://leetcode.com/problems/queue-reconstruction-by-height/submissions/)

   - sort the vector in descending order of the heights and ascending order of same height's k value.
   - iterate over the vector and insert the heights at the kth index because higher heights have already been inserted.

4. [Max area of piece of cake](https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/submissions/)

   - Sort the horizontal and vertical cuts and find the largest diff in horizontal and vertical cuts.
   - multiply both of them to get the ans

5. [Wiggle subsequence](https://leetcode.com/problems/wiggle-subsequence/submissions/)

   - peak and valley are two variable because we dont know whether the first element is peak or a valley
   - https://leetcode.com/problems/wiggle-subsequence/discuss/2229495/C%2B%2B-O-(-N-)-oror-EXPLAINED-oror

6. [Distribute Candies](https://leetcode.com/problems/candy/submissions/)

   - Assign all the values as 1 since 1 is the minimum amount of candies everyone will get.
   - in the first loop check if a[i] > a[i-1], if yes then update c[i] = c[i-1]+1;
   - but with this loop only left part is calculated, when taking into account the right part of the array the values might increase.
   - looping from the back and checking if a[i] > a[i+1] && c[i]<=c[i+1], if yes then update c[i] = c[i+1]+1
   - c[i] <= c[i+1] because if the count is already greater than c[i+1] then there is no need of increasing the values.
