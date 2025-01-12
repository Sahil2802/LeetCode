class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(); // Get the size of the array

        // Edge cases:
        if (n == 1) return nums[0]; // If the array has only one element, return that element
        if (nums[0] != nums[1]) return nums[0]; // If the first element is unique, return it
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1]; // If the last element is unique, return it

        int low = 1, high = n - 2; // Initialize low and high pointers, excluding the first and last elements

        // Binary search loop
        while (low <= high) {
            int mid = low + (high - low) / 2; // Calculate the middle index

            // Check if the middle element is the single non-duplicate element
            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
                return nums[mid]; // If it is, return the middle element
            }

            // Determine which half to eliminate
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                // If we are in the left half, move the low pointer to mid + 1
                low = mid + 1;
            } else {
                // If we are in the right half, move the high pointer to mid - 1
                high = mid - 1;
            }
        }

        // If no single element is found, return -1 (this case should not occur with valid input)
        return -1;
    }
};