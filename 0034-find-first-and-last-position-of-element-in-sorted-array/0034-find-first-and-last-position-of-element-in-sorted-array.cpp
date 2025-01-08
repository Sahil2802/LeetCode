class Solution {
private:
    // Function to find the left bound of the target
    int findLeftBound(vector<int>& nums, int target) {
        int index = -1; // Initialize index to -1, indicating target not found initially
        int low = 0, high = nums.size() - 1; // Initialize the low and high pointers for binary search

        // Perform binary search to find the left bound
        while (low <= high) {
            int mid = (low + high) / 2; // Calculate the middle index of the current search range
            if (nums[mid] == target) { // Check if the middle element is equal to the target
                index = mid; // Update index to the current mid, as it is a potential left bound
                high = mid - 1; // Move the high pointer to the left half to find the first occurrence
            } else if (nums[mid] > target) { // If the middle element is greater than the target
                high = mid - 1; // Move the high pointer to the left half
            } else { // If the middle element is less than the target
                low = mid + 1; // Move the low pointer to the right half
            }
        }
        return index; // Return the index of the left bound
    }

    // Function to find the right bound of the target
    int findRightBound(vector<int>& nums, int target) {
        int index = -1; // Initialize index to -1, indicating target not found initially
        int low = 0, high = nums.size() - 1; // Initialize the low and high pointers for binary search

        // Perform binary search to find the right bound
        while (low <= high) {
            int mid = (low + high) / 2; // Calculate the middle index of the current search range
            if (nums[mid] == target) { // Check if the middle element is equal to the target
                index = mid; // Update index to the current mid, as it is a potential right bound
                low = mid + 1; // Move the low pointer to the right half to find the last occurrence
            } else if (nums[mid] > target) { // If the middle element is greater than the target
                high = mid - 1; // Move the high pointer to the left half
            } else { // If the middle element is less than the target
                low = mid + 1; // Move the low pointer to the right half
            }
        }
        return index; // Return the index of the right bound
    }

public:
    // Function to find the starting and ending position of a given target in a sorted array
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findLeftBound(nums, target); // Find the left bound
        if(first == -1) return {-1, -1};
        int last = findRightBound(nums, target); // Find the right bound

        return {first, last}; // Return the left and right bounds as a vector
    }
};