1. [M coloring problem](https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#)

   - Trying every color from 1 to m with the help of a for a loop.
   - Is safe function returns true if it is possible to color it with that color i.e none of the adjacent nodes have the same color.
   - In case this is an algorithm and follows a certain intuition.
   - Color it with color i then call the recursive function for the next node if it returns true we will return true.And If it is false then take off the color. Now if we have tried out every color from 1 to m and it was not possible to color it with any of the m colors then return false.

2. [Word Break 2](https://leetcode.com/problems/word-break-ii/submissions/)

- take two pointers 1. prev 2. curr
- increament the curr pointer and check whether substr(prev,curr-prev+1) is a valid word or not
- if yes then increament the prev and curr to curr+1.
- and call the function recursively with the above values

3. [Match stick to square](https://leetcode.com/problems/matchsticks-to-square/submissions/)

   - Every matchstick can belong to either of the 4 sides. We don't know which one. Maybe try out all options!
   - For every matchstick, we have to try out each of the 4 options i.e. which side it can belong to. We can make use of recursion for this.
   - When all matchsticks have been used we simply need to see the length of all 4 sides. If they're equal, we have a square on our hands!
