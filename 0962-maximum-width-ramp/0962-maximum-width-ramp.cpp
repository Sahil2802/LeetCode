class Solution {
public:
    // find two indices where the left value is ≤ right value, and maximize their distance. 
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();

        // rightMax[j] stores the maximum value from nums[j..n-1].
        vector<int> rightMax(n);
        rightMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], nums[i]);
        }

        int i = 0;      // left pointer
        int j = 0;      // right pointer
        int ramp = 0;   // best width found so far

        while (j < n) {
            // Move left pointer until nums[i] <= some value at or after j.
            while (i < j && nums[i] > rightMax[j]) {
                i++;
            }

            // Now nums[i] <= rightMax[j], so a valid ramp exists with j.
            ramp = max(ramp, j - i);
            j++;
        }

        return ramp;
    }
};