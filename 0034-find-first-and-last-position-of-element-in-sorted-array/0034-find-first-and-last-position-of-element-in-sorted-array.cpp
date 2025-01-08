class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size(); // Get the size of the input vector
        int start = -1, last = -1; // Initialize start and last to -1, indicating target not found initially

        // Iterate through the vector to find the target
        for(int i = 0; i < n; i++){
            if(nums[i] == target){ // Check if the current element is equal to the target
                if(start == -1){ // If start is -1, it means this is the first occurrence of the target
                    start = i; // Set start to the current index
                }
                last = i; // Update last to the current index (this will be the last occurrence of the target)
            }
        }
        // Return the start and last indices as a vector
        return {start, last};
    }
};