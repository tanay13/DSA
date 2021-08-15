class Solution {
public:
    int res[21][2005];
    int sum = 0;
    int findTargetSumWays(vector<int>& nums, int S) {
       for(int i=0;i<21;i++)
           for(int j=0;j<2005;j++)
                res[i][j] = -1;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        int result = numWays(S,nums,nums.size()-1);
        return result;
        
    }
    
    
    int numWays(int target, vector<int> &nums,int index)
    {
    int target1;
    if(abs(target)>sum)
            return 0;
     if(target<0)
     {
         target1 = 1000+abs(target);
     }
     else
     {
         target1 = target;
     }
     
     if(target!=0 && index==-1)
     {
         return 0;
     }
     if(target==0 && index==-1)
     {
         return 1;
     }
        
     if(res[index][target1]!=-1)
         return res[index][target1];
      else
      {
          
              res[index][target1] = numWays(target-nums[index],nums,index-1)+numWays(target+nums[index],nums,index-1);
          
          return res[index][target1];
      }
        
        
    }