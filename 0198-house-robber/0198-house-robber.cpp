class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // Edge case: If there's only one house, return its value
        if(n == 1) return nums[0];
    
        // prev2: max amount robbed up to house i-2
        // prev1: max amount robbed up to house i-1
        int prev2 = nums[0]; // Only the first house can be robbed
        int prev1 = max(nums[0], nums[1]); // Max of robbing the first or second house

        // Iterate through the rest of the houses
        for(int i = 2; i < n; i++){
            // Option 1: Rob the current house and add the result from i-2 (prev2)
            int pick = nums[i] + prev2; 
            // Option 2: Do not rob the current house, take the result from i-1 (prev1)
            int notPick = prev1;

            // Current max is the best of picking or not picking the current house
            int curr = max(pick, notPick);

            // Update prev2 and prev1 for the next iteration
            prev2 = prev1;
            prev1 = curr; 
        }
        // prev1 holds the answer: the max amount that can be robbed
        return prev1;
    }
};