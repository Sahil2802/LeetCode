class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        // Binary search loop
        while (low <= high) {
            int mid = low + (high - low) / 2; // Calculate the middle index

            // Check if the middle element is the target
            if (nums[mid] == target) return true;

            // If elements at low, mid, and high are equal, we cannot determine the sorted part
            if (nums[low] == nums[mid] && nums[high] == nums[mid]) {
                low = low + 1; // Increment low
                high = high - 1; // Decrement high
                continue; // Continue to the next iteration
            }

            // Check if the left part is sorted
            else if (nums[low] <= nums[mid]) {
                // Check if the target is within the sorted left part
                if (nums[low] <= target && nums[mid] >= target) {
                    high = mid - 1; // Move the high pointer to mid - 1
                } else {
                    low = mid + 1; // Move the low pointer to mid + 1
                }
            }

            // Otherwise, the right part must be sorted
            else {
                // Check if the target is within the sorted right part
                if (nums[mid] <= target && nums[high] >= target) {
                    low = mid + 1; // Move the low pointer to mid + 1
                } else {
                    high = mid - 1; // Move the high pointer to mid - 1
                }
            }
        }
        // If we exit the loop, the target was not found
        return false;
    }
};