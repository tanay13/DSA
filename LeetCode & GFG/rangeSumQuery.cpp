class NumArray {
public:
    NumArray(vector<int> nums) {
        int n = nums.size();
        sums.resize(n + 1);
        sums[0] = 0;
        for(int i = 0; i < n; ++i){
            sums[i + 1] = sums[i] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
    
    vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_ = obj->sumRange(left,right);
 */