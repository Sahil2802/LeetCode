class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // Sort the array so the smallest element can be paired with the largest.
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int l = 0, r = n - 1;

        // Stores the maximum pair sum seen so far.
        int result = 0;

        // Pair elements from both ends toward the center.
        while (l < r) {
            int sum = nums[l] + nums[r];

            // Track the largest sum among all pairs.
            result = max(result, sum);

            l++;
            r--;
        }

        return result;
    }
};