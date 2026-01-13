class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int total = 1 << n;  // Calculate 2^n (total number of subsets)
        vector<vector<int>> result;
        
        // Iterate through all possible binary patterns (0 to 2^n - 1)
        // Each number represents a unique subset via its bit pattern
        for(int mask = 0; mask < total; mask++){
            vector<int> subset;
            
            // Check each bit position in the current mask
            for(int i = 0; i < n; i++){
                // If bit i is set (1) in mask, include nums[i] in subset
                if(mask & (1 << i)){
                    subset.push_back(nums[i]);
                }
            }
            result.push_back(subset);
        }
        return result;   
    }
};