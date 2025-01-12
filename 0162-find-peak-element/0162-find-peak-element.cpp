class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size(); // Get the size of the array

        // Edge cases:
        if (n == 1) return 0; // If the array has only one element, return the index 0
        if (nums[0] > nums[1]) return 0; // If the first element is greater than the second, return the index 0
        if (nums[n - 1] > nums[n - 2]) return n - 1; // If the last element is greater than the second last, return the index n - 1

        int low = 1, high = n - 2; // Initialize low and high pointers, excluding the first and last elements

        // Binary search loop
        while (low <= high) {
            int mid = low + (high - low) / 2; // Calculate the middle index

            // Check if the middle element is a peak element
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid; // If it is, return the middle element's index
            }

            // Determine which half to eliminate
            else if (nums[mid] > nums[mid - 1]) {
                // If the middle element is greater than the previous element, move the low pointer to mid + 1
                low = mid + 1;
            } else {
                // If the middle element is not greater than the previous element, move the high pointer to mid - 1
                high = mid - 1;
            }
        }
        // If no peak element is found, return -1 (this case should not occur with valid input)
        return -1;
    }
};