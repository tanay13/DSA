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
