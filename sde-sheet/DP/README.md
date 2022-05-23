1. [Palindromic subsequence](https://leetcode.com/problems/palindromic-substrings/submissions/)

   - ![img](../ss/palindromic.png)
   - Start filling the table backwards
   - Checking if dp[start+1][end-1] == 1 to ensure the substring from start+1 to end-1 is a palindrom
