class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(); // Get the size of the array
        int low = 0, high = n - 1; // Initialize low and high pointers
        int ans = INT_MAX; // Initialize the answer to the maximum possible integer value

        // Binary search loop
        while (low <= high) {
            int mid = low + (high - low) / 2; // Calculate the middle index
            // if the whole array is sorted
            if(nums[low] <= nums[high]){
                ans = min(ans, nums[low]);
                break;
            }
            // Check if the left part is sorted
            if (nums[low] <= nums[mid]) {
                // Update the answer with the minimum value found so far
                ans = min(ans, nums[low]);
                // Move the low pointer to mid + 1 to search in the right part
                low = mid + 1;
            } else {
                // If the left part is not sorted, the right part must be sorted
                // Update the answer with the minimum value found so far
                ans = min(ans, nums[mid]);
                // Move the high pointer to mid - 1 to search in the left part
                high = mid - 1;
            }
        }
        // Return the minimum value found
        return ans;
    }
};