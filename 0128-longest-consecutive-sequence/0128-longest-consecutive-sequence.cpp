class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // Sort the array

        // If the array is empty, return 0
        if (n == 0) {
            return 0; 
        }

        int currConsecutive = 1; // Initialize the current consecutive sequence length
        int longestConsecutive = 1; // Initialize the longest consecutive sequence length

        // Iterate through the sorted array
        for (int i = 1; i < n; i++) {
            // Skip duplicates
            if (nums[i] != nums[i - 1]) { 
                if (nums[i] == nums[i - 1] + 1) {
                    currConsecutive++; // Increment the current sequence length
                    longestConsecutive = max(longestConsecutive, currConsecutive); // Update the longest sequence length
                } else {
                    currConsecutive = 1; // Reset the current sequence length
                }
            }
        }

        return longestConsecutive; 
    }
};