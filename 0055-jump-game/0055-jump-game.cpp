class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(); // Get the size of the array
        int maxIndex = 0;    // Tracks the farthest index we can reach

        // Iterate through the array
        for (int i = 0; i < n; i++) {
            // If the current index is beyond the farthest reachable index, return false
            if (i > maxIndex) return false;

            // Update the farthest reachable index
            maxIndex = max(maxIndex, i + nums[i]);

            // If the farthest reachable index is already beyond or at the last index, return true
            if (maxIndex >= n - 1) return true;
        }

        // If we finish the loop, it means we can reach the last index
        return true;
    }
};