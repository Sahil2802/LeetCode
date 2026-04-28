class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;  // pointer to place the next valid (non-val) element

        // iterate through the entire array
        for (int i = 0; i < nums.size(); i++) {

            // if current element is NOT equal to val
            if (nums[i] != val) {

                // place it at index k (front part of array)
                nums[k] = nums[i];

                // move k forward to next position
                k++;
            }
            // if nums[i] == val → we skip it (do nothing)
        }

        // k represents the number of valid elements (not equal to val)
        return k;
    }
};