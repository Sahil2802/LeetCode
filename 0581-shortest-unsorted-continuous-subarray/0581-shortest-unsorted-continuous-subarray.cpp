class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted_nums = nums; // copy
        sort(sorted_nums.begin(), sorted_nums.end());

        int left = 0, right = n - 1;

        // Find first index where original and sorted differ
        while (left < n && nums[left] == sorted_nums[left]) {
            left++;
        }

        // Already fully sorted
        if (left == n) return 0;

        // Find last index where original and sorted differ
        while (right >= 0 && nums[right] == sorted_nums[right]) {
            right--;
        }

        return right - left + 1;
    }
};