1. [Furthest building you can reach](https://leetcode.com/problems/furthest-building-you-can-reach/submissions/)

   - Maintaining a min heap (priority queue) and storing the highest jumps.
   - highest jumps are to be taken by the ladders and the rest using bricks

2. [Construct target array](https://leetcode.com/problems/construct-target-array-with-multiple-sums/submissions/)

   - https://leetcode.com/problems/construct-target-array-with-multiple-sums/discuss/2189445/Visual-Explanation-or-JAVA-Max-Heap

3. [Course Schedule 3](https://leetcode.com/problems/course-schedule-iii/submissions/)

   - sorting on the basis of ending time
   - iterating over the array and adding the duration in the max heap.
   - if the total duration exceeds the current element's deadline then we remove the biggest course we have added till now(p.top())
   - at the end the size of the max heap is the total course we can do

4. [Min number of refueling stop](https://leetcode.com/problems/minimum-number-of-refueling-stops/submissions/)

   - First go to the max distance we can go using the startFuel and push the gas value in the PQ which had distance less than startFuel.
   - Once the max Distance is reached we add the highest values from the priority queue to the startFuel to increase the max distance
