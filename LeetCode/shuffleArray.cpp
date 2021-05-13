class Solution {
public:
    map<int,int> m;
    vector<int> vec;
    Solution(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            vec.push_back(nums[i]);
            m[i] = nums[i];
        }
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        for(int i=0;i<vec.size();i++)
        {
            vec[i] = m[i];
        }
        return vec;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i=0;i<vec.size();i++)
        {
            int random = (rand() % (vec.size()));
            int temp;
            temp = vec[random];
            vec[random] = vec[i];
            vec[i] = temp; 
        }
        return vec;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */