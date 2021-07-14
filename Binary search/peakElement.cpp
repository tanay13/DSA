class Solution {
public:
    bool found = false;
    int index;
    int findPeakElement(vector<int>& nums) {
        
        int start = 0;
        int end = nums.size()-1;
        
        if(nums.size() == 1)
        {
            return 0;
        }
        
        peak(start,end,end-start+1,nums);
        
        return index;
        
    }
    
    void peak(int start,int end,int size,vector<int>&nums)
    {
        
        if(start>end)
            return;
        
        int mid = start+(end-start)/2;
        
        if(mid!=0 && mid!=nums.size()-1)
        {
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
            {
                found = true;
                index = mid;
            }
        }
        else if(mid==0)
        {

                if(nums[mid]>nums[mid+1])
                {
                    found = true;
                    index = mid;
                }
                    
    
        }
        else if(mid == nums.size()-1)
        {
            
                if(nums[mid]>nums[mid-1])
                {
                    found = true;
                    index = mid;
                }
                    
           
        }
        
        if(!found)
        {
            peak(start,mid-1,mid-1-start+1,nums);
        }
        if(!found)
        {
            peak(mid+1, end, end-(mid+1)+1,nums);
        }
        
        return;
        
    }
};