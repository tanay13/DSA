class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int i = 0;
        
        while(i<nums.size())
        {
            
            if(nums[i]<nums.size() && nums[i]>0 && nums[i]!=nums[nums[i]-1])
            {
                int temp = nums[nums[i]-1];
                nums[nums[i]-1] = nums[i];
                nums[i] = temp;
            }
            else
                i++;
        }
        
        vector<int> v;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=i+1)
            {
                return i+1;
            }
                
        }
        
        return nums.size()+1;
        
    }
};