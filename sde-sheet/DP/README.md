1. [Palindromic subsequence](https://leetcode.com/problems/palindromic-substrings/submissions/)

   - ![img](../ss/palindromic.png)
   - Start filling the table backwards
   - Checking if dp[start+1][end-1] == 1 to ensure the substring from start+1 to end-1 is a palindrom

2. [Ones and Zeroes](https://leetcode.com/problems/ones-and-zeroes/submissions/)

   - 0/1 knapsack pattern
   - 3D array

3. [Regex Matching](https://leetcode.com/problems/regular-expression-matching/submissions/)

   - If the next char of the pattern string is \* then we have two option
   - either to take the char associated with the \* or ignore it.

4. [Delete operation for two string](https://leetcode.com/problems/delete-operation-for-two-strings/)

   - find LCS and then substract the length with both the words and add it to find the number of chars to be deleted

5. [Longest Palindromic substring](https://leetcode.com/problems/longest-palindromic-substring/)

   - We use diagonal DP and fill the first two cell of every row , first cell with 1 and the second cell with 1 if (s[i] == s[i+1]) otherwise 0
   - Starting from the bottom of the 2D array we fill the cell with 1 if (s[i] == s[j] && dp[i+1][j-1] == 1 ) because it tells that the string between the starting and the current index is also a palindrom.

6. [Longest string Chain](https://leetcode.com/problems/longest-string-chain/submissions/)

   - In this approach, we are creating a vector which at every index stores the length of the chain ending at that particular index.
   - This means that at any index i, we store the chain length that ends at the string corresponding to the ith index.
   - dp[i] < dp[prev]+1 checks that if we add the prev index string to the chain, will it increase the chain length or not,
   - if the chain length is not increasing by adding the prev index string then it won't form the longest chain ending at the ith index, if the prev index string creates a longer chain ending at ith index then we add it to the chain and increase the value of the current index.

7. [Edit Distance](https://leetcode.com/problems/edit-distance/submissions/)

   - If chars are same then do i-1 j-1 otherwise take into all 3 cases possible
   - that is insert delete replace

8. [Buy sell stock 2](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)

9. [Buy sell stock 3](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/submissions/)

10. [Buy sell stock 3](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/submissions/)

11. [Number of LIS](https://www.codingninjas.com/codestudio/problems/number-of-longest-increasing-subsequence_3751627?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1)

    - maintaining a count array with all values of 1.
    - count[i] will store the LIS count which ends at ith index.
    - if dp[j]+1 > dp[i] then it means that count[i] will be equal to count[j] if dp[j]+1 == dp[i] then count[i]+=count[j] because LIS count is getting increased

12. [Min cost stairs](https://leetcode.com/problems/min-cost-climbing-stairs/submissions/)

13. [Min cost to cut sticks](https://leetcode.com/problems/minimum-cost-to-cut-a-stick/)

14. [Burst balloons](https://leetcode.com/problems/burst-balloons/submissions/)

    - Assume the kth balloon in bursted in the last between the interval [i,j]
    - If k is the last balloon to be bursted in the [i,j] interval then we will have to solve for the subproblem of func(i,k-1) and func(k+1,j)
    - These two subproblem will be independent because both of the are only dependant on the kth element since it is bursted at the end

15. [Interleaving Strings](https://leetcode.com/problems/interleaving-string/submissions/)

    - For each char in s3 string we check the possibilty whether the element belongs to string s1 or s2 recursively.

16. [Paint House 3](https://leetcode.com/problems/paint-house-iii/submissions/)

17. [Jump game 6](https://leetcode.com/problems/jump-game-vi/submissions/)

    - Maintain a deque of {dp[i],index} pair where the front elements are the highest element withing i+k range.
    - dp[i] denotes the score of reaching at the end from ith element
    - therefore dp[n-1] = nums[n-1]
    - start iterating from n-2 and check if the front element is in the range or not, if not then pop the front value and set the dp[i] = nums[i]+deq.front().first
    - because the first element is the highest score we can attain if we jump on any element within i+k range
