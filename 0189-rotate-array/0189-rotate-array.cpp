class Solution {
public:
    // Function to reverse elements in the array from index 'left' to 'right'
    void reverse(vector<int> &nums, int left, int right) {
        int lp = left;
        int rp = right;

        // Swap elements from the two ends
        while (lp < rp) {
            int temp = nums[lp];
            nums[lp] = nums[rp];
            nums[rp] = temp;
            lp++;
            rp--;
        }
    }

    // Function to rotate the array to the right by 'k' positions
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Ensure k is within the bounds of the array length

        // Reverse the first part of the array (from 0 to n-k-1)
        reverse(nums, 0, n-k-1);
        // Reverse the second part of the array (from n-k to n-1)
        reverse(nums, n-k, n-1);
        // Reverse the entire array
        reverse(nums, 0, n-1);
    }
};
