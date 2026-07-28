class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); // needed for two-pointer technique
        int n = nums.size();

        int closestSum = nums[0] + nums[1] + nums[2]; // initialize with any valid triplet

        for (int i = 0; i < n; i++) {
            int left = i + 1, right = n - 1; // two pointers on the remaining sorted range

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                // Update closestSum if this triplet is nearer to target
                if (abs(sum - target) < abs(closestSum - target)) {
                    closestSum = sum;
                }

                if (sum == target) {
                    return sum; // exact match, impossible to get closer than this
                } else if (sum < target) {
                    left++;  // sum too small, move left pointer right to increase it
                } else {
                    right--; // sum too big, move right pointer left to decrease it
                }
            }
        }
        return closestSum;
    }
};