class Solution {
public:
    // Function to search for a target value in a rotated sorted array
    int search(vector<int>& nums, int target) {
        int n = nums.size(); // Get the size of the input vector
        int low = 0, high = n - 1; // Initialize the low and high pointers for binary search

        // Perform binary search
        while (low <= high) {
            int mid = low + (high - low) / 2; // Calculate the middle index of the current search range

            // Check if the middle element is the target
            if (nums[mid] == target) return mid;

            // Check if the left part is sorted
            if (nums[low] <= nums[mid]) {
                // Check if the target is within the sorted left part
                if (nums[low] <= target && nums[mid] >= target) {
                    high = mid - 1; // Move the high pointer to the left half
                } else {
                    low = mid + 1; // Move the low pointer to the right half
                }
            }
            // If the right part is sorted
            else {
                // Check if the target is within the sorted right part
                if (nums[mid] <= target && nums[high] >= target) {
                    low = mid + 1; // Move the low pointer to the right half
                } else {
                    high = mid - 1; // Move the high pointer to the left half
                }
            }
        }
        return -1; // Return -1 if the target is not found
    }
};