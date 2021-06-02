    int maximumUniqueSubarray(vector<int>& nums) {
        
        int result = 0;
        unordered_set<int> umap;
        for (int i = 0, j = 0, score = 0; j < nums.size(); j++) {
            while (umap.find(nums[j]) != umap.end()) {
                umap.erase(nums[i]);
                score -= nums[i];
                i++;
            }
            umap.insert(nums[j]);
            score += nums[j];
            result = max(result, score);
        }
        return result;
        
        
    }