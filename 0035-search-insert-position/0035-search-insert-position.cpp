class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size(); // Get the size of the input vector
        int low = 0, high = n - 1; // Initialize the low and high pointers for binary search
        int ans = n; // Initialize ans to n, which is the size of the array (default position if target is greater than all elements)

        // Perform binary search
        while (low <= high) {
            int mid = (low + high) / 2; // Calculate the middle index of the current search range

            // Check if the middle element is greater than or equal to the target
            if (nums[mid] >= target) {
                ans = mid; // Update ans to the current mid, as it is a potential insertion point
                high = mid - 1; // Move the high pointer to the left half to find a smaller or equal element
            } else {
                low = mid + 1; // Move the low pointer to the right half to find a larger element
            }
        }
        return ans; // Return the index where the target should be inserted
    }
};