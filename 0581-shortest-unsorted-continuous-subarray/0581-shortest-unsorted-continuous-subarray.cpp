class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = -1, right = -1;

        // Left to right: track running max (biggest value seen so far)
        int maxSoFar = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxSoFar = max(nums[i], maxSoFar);
            // If current element is smaller than max seen before it,
            // it's out of place -> extend the right boundary
            if (nums[i] < maxSoFar) {
                right = i;
            }
        }

        // Array is already fully sorted, nothing to do
        if (right == -1) return 0;

        // Right to left: track running min (smallest value seen so far)
        int minSoFar = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            minSoFar = min(nums[i], minSoFar);
            // If current element is bigger than min seen after it,
            // it's out of place -> extend the left boundary
            if (nums[i] > minSoFar) {
                left = i;
            }
        }

        // Length of the shortest subarray that needs sorting
        return right - left + 1;
    }
};