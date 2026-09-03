class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();

        // i scans through every element
        // j marks the boundary: everything before j is already even
        int i = 0, j = 0;

        while (i < n) {
            if (nums[i] % 2 == 0) {
                // nums[i] is even, so it belongs on the left.
                // swap it into position j (the next open "even" slot).
                swap(nums[i], nums[j]);
                i++;
                j++;
            } else {
                // nums[i] is odd, leave it where it is for now,
                // just move on to check the next element.
                i++;
            }
        }

        return nums;
    }
};