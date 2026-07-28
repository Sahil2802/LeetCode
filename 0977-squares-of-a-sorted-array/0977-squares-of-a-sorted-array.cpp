class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);

        int left = 0, right = n - 1; // two pointers at the ends

        // Fill result from the back — largest square goes to the highest index
        for (int i = n - 1; i >= 0; i--) {
            // The bigger absolute value produces the bigger square
            if (abs(nums[left]) > abs(nums[right])) {
                result[i] = nums[left] * nums[left];
                left++;   // done with this left element, move inward
            } else {
                result[i] = nums[right] * nums[right];
                right--;  // done with this right element, move inward
            }
        }
        return result;
    }
};