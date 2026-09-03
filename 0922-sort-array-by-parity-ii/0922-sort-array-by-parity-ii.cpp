class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();

        int even = 0, odd = 1; // even walks even indices, odd walks odd indices
        while (even < n && odd < n) {
            if (nums[even] % 2 == 0) {
                // even index already holds an even value, move on
                even += 2;
            } else if (nums[odd] % 2 == 1) {
                // odd index already holds an odd value, move on
                odd += 2;
            } else {
                // even index has an odd value and odd index has an even value: fix both with one swap
                swap(nums[even], nums[odd]);
            }
        }
        return nums;
    }
};
