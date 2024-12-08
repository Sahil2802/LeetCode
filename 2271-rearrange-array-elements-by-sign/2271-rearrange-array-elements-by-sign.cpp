class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int posIdx = 0, negIdx = 1; // Initialize indices for positive and negative numbers
        int n = nums.size(); 
        vector<int> ans(n, 0); 

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans[posIdx] = nums[i]; // Place positive number at posIdx
                posIdx += 2; // Move to the next position for positive number
            } else {
                ans[negIdx] = nums[i]; // Place negative number at negIdx
                negIdx += 2; // Move to the next position for negative number
            }
        }

        return ans; 
    }
};