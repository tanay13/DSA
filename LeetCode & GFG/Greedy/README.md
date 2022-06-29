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
