class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // Initialize a hash array of size n+1 with all elements set to 0
        vector<int> hash(n + 1, 0);

        // Mark the each number presetnt in nums[1] in the hash array to 1
        for (int i = 0; i < n; i++) {
            hash[nums[i]] = 1;
        }

        // Find the missing number by checking the hash array
        for (int i = 1; i <= n; i++) {
            if (hash[i] == 0) { // 0 in the hash array is the missing number
                return i; // Return the missing number
            }
        }

        // If no number is missing, return 0 (this case should not occur with valid input)
        return 0;
    }
};
