class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // Edge cases: no houses or only one house
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        
        // Compute max sum for range [0, n-2] (exclude last house)
        int firstToSecondLast = helper(0, n-2, nums);
        // Compute max sum for range [1, n-1] (exclude first house)
        int secondToLast = helper(1, n-1, nums);

        // Return the maximum of the two cases
        return max(firstToSecondLast, secondToLast);
    }

private:
    // Helper function to compute max sum for houses in range [start, end] using space optimization
    int helper(int start, int end, vector<int> &nums){
        int len = end - start + 1; 
        // If only one house in the range, return its value
        if (len == 1) return nums[start];

        // prev2: max sum up to house at index start
        int prev2 = nums[start];
        // prev1: max sum up to house at index start + 1
        int prev1 = max(nums[start], nums[start + 1]);
    
        // Iterate through the rest of the houses in the range
        for(int i = 2; i < len; i++){
            // Option 1: Pick the current house and add prev2 (i-2)
            int pick = nums[start + i] + prev2;
            // Option 2: Do not pick the current house, take prev1 (i-1)
            int notPick = prev1;
            // Current max sum is the max of picking or not picking
            int curr = max(pick, notPick);

            // Update prev2 and prev1 for the next iteration
            prev2 = prev1;
            prev1 = curr;
        }
        // prev1 holds the answer for this range
        return prev1;
    }
};