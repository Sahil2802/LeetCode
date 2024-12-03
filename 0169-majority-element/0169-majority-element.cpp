class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele; // Variable to store the potential majority element
        int count = 0; // Counter to track the potential majority element
        int n = nums.size(); 

        for (int i = 0; i < n; i++) {
            if (count == 0) {
                // If count is 0, set the current element as the candidate
                count = 1;
                ele = nums[i];
            } else if (nums[i] == ele) {
                // If the current element is the same as the candidate, increment the count
                count++;
            } else {
                // If the current element is different from the candidate, decrement the count
                count--;
            }
        }
        return ele;
    }
};