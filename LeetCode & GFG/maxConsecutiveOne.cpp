class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int one = 0,zero=0,start=0;
        int max = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
             if(nums[i]==0)
                zero++;
            if(zero>k)
            {
                while(zero>k)
                {
                    if(nums[start]==0)
                    {
                        zero--;
                        start++;
                    }
                    else
                        start++;
                }
            }
           
            
            if(max<(i-start+1))
                max = (i-start+1);
            
            
            
        }
        return max;
    }
};