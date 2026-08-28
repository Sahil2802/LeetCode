class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // sort the aarray so that so we can optimally use triangle prop. a + b > c
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int count = 0;

        // Fix nums[k] as the largest side of the triangle.
        // We only need k >= 2 since starting 2 elements have i and j pointer.
        for (int k = n - 1; k >= 2; k--) {
            int i = 0;       // left pointer, starts at smallest element
            int j = k - 1;   // right pointer, starts just before nums[k]

            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    // Since array is sorted, if nums[i] + nums[j] > nums[k],
                    // then nums[i+1] + nums[j], nums[i+2] + nums[j], are also > nums[k]
                    // So all pairs (i, j), (i+1, j), ..., (j-1, j) form valid triangles.
                    count += (j - i); // That's (j - i) valid pairs with this j.

                    // Move j left to check smaller "second largest" side.
                    j--;
                } else {
                    // Sum too small, need a bigger left value.
                    i++;
                }
            }
        }

        return count;
    }
};