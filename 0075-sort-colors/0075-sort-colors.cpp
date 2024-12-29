class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(); 
        int low = 0, mid = 0, high = n - 1; // Initialize pointers

        // Traverse through the array and swap with either low or high with the help of mid pointer
        // Process elements until the mid pointer crosses the high pointer
        while (mid <= high) {
            if (nums[mid] == 0) {
                // If the current element is 0, swap it with the element at the low pointer
                swap(nums[low], nums[mid]);
                // Increment both low and mid pointers
                low++;
                mid++;
            } 
            else if (nums[mid] == 1) {
                // If the current element is 1, just increment the mid pointer
                mid++;
            } 
            else {
                // If the current element is 2, swap it with the element at the high pointer
                swap(nums[mid], nums[high]);
                // Decrement the high pointer
                high--;
            }
        }
    }
};