class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(); 
        int index = -1; // Initialize the break point index to -1

        // Step 1: Find the break point
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i; // Set the break point index
                break; // Exit the loop once the break point is found
            }
        }

        // If no break point is found, reverse the entire array
        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return; // Return early as the array is now the smallest permutation
        }

        // Step 2: Find the next greater element and swap it with nums[index]
        for (int i = n - 1; i > index; i--) {
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]); // Swap the elements
                break; // Exit the loop once the swap is done
            }
        }

        // Step 3: Reverse the elements to the right of the break point
        reverse(nums.begin() + index + 1, nums.end());
    }
};