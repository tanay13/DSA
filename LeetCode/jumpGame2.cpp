    int jump(vector<int>& nums) {
        
      int n = nums.size();
      int farthest = nums[0];
      int curr_far = nums[0];
        
        int jumps = 1;
        
        if(n==1 || nums[0]==0)
            return 0;
        
        
        for(int i = 1;i<n;i++)
        {
            if(i==n-1)
                return jumps;
            farthest = max(farthest,nums[i]+i);
            
            if(i== curr_far)
            {
                curr_far = farthest;
                jumps++;
            }
        }
        return jumps;

        
        
    }