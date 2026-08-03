class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n; // arrays of size 0, 1, or 2 are always valid as-is

        int k = 2; // write pointer; first two elements are always kept

        for (int i = 2; i < n; i++) {
            // Compare with the element 2 slots back in our result-so-far.
            // If it matches, nums[i] would be a 3rd copy -> skip it.
            // If it differs, it's safe to keep (new value or 2nd copy).
            if (nums[i] != nums[k-2]) {
                nums[k] = nums[i]; // write valid element into next result slot
                k++;                // advance write pointer
            }
        }

        return k; // length of the valid deduplicated portion
    }
};