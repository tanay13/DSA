class Solution {
public:
    int memo[1000] = {0};
    int arr[2] = {1,2};
    int climbStairs(int n) {
        if(memo[n]!=0) return memo[n];
        if(n==2) return memo[n]+2;
        if(n==1) return memo[n]+1;
        for(int i=0;i<2;i++)
        {
            int rem = n-arr[i];
            memo[n] = memo[n]+climbStairs(rem);
        }
        return memo[n];
    }
};