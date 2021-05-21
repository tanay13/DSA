class Solution{
	public:
	int dp[10001] = {0};
	int MinSquares(int n)
	{
	    // Code here
	    if(dp[n]!=0)
	    return dp[n];
	    if(n == 1)
	      return 1;
	    if(n ==2)
	    return 2;
	    if(n == 0)
	    return 0;
	    int minimum = 10000;
	    for(int i=1;i<=sqrt(n);i++)
	    {
	       minimum = min(MinSquares(n-i*i)+1,minimum);
	       dp[n] = minimum;
	    }
	    return dp[n];
	    
	}
};