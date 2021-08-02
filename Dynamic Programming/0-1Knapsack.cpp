class Solution
{
    public:
    
    int ans(int W, int wt[], int val[], int n,int** dp)
    {
       
        
        if(W==0 || n==0)
            return 0;
            
         if(dp[n][W]!=-1)
            return dp[n][W];
        
       
       if(wt[n-1] > W)
       {
          dp[n][W] = ans(W,wt,val,n-1,dp);
          return dp[n][W];
       }
       else
       {
           dp[n][W] = max(val[n-1]+ans(W-wt[n-1],wt,val,n-1,dp),ans(W,wt,val,n-1,dp));
           return dp[n][W];
       }
          
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
      
        int** dp;
        dp = new int*[n+1];

    
        for (int i = 0; i < n+1; i++)
            dp[i] = new int[W + 1];

    
        for (int i = 0; i < n+1; i++)
            for (int j = 0; j < W + 1; j++)
                dp[i][j] = -1;
       
        int a = ans(W,wt,val,n,dp);
       
        return a;
       
    }
    
    
};