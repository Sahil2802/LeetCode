#include <vector>
using namespace std;

class Solution {
public:
    // Function to perform binary search on a sorted vector
    int search(vector<int>& nums, int target) {
        int n = nums.size(); // Get the size of the input vector
        int l = 0, r = n - 1; // Initialize left and right boundaries of the search range

        // Loop to perform binary search
        while (l <= r) {
            int mid = (l + r) / 2; // Calculate the middle index of the current search range

            // Check if the target is equal to the middle element
            if (target == nums[mid]) {
                return mid; // Target found, return the index
            }
            // Check if the target is less than the middle element
            else if (nums[mid] > target) {
                r = mid - 1; // Update the right boundary to search in the left half
            }
            // Check if the target is greater than the middle element
            else {
                l = mid + 1; // Update the left boundary to search in the right half
            }
        }

        return -1; // Target not found, return -1
    }
};