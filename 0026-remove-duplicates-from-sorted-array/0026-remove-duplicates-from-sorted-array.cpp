class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Initialize a pointer i to keep track of the position of unique elements
        int i = 0;

        // Iterate through the arr starting from the second element
        for(int j = 1; j < nums.size(); j++) {
            // If the current element is different from the last unique element
            if(nums[i] != nums[j]) {
                i++; // Move the pointer to the next position
                nums[i] = nums[j]; // update the element at position i with the unique element found at j
            }
        }

        // Return the number of unique elements
        return i + 1;
    }
};