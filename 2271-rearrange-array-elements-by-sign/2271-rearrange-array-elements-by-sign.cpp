class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos; // Vector to store positive numbers
        vector<int> neg; // Vector to store negative numbers
        int n = nums.size(); 

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                pos.push_back(nums[i]); // Add positive number to pos vector
            } else {
                neg.push_back(nums[i]); // Add negative number to neg vector
            }
        }

        for (int i = 0; i < n / 2; i++) {
            nums[i * 2] = pos[i]; // Place positive number at even index
            nums[i * 2 + 1] = neg[i]; // Place negative number at odd index
        }

        return nums; 
    }
};