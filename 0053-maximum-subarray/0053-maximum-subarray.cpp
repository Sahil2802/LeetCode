class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0; 
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i]; // Add the current element to the sum
            maxi = max(maxi, sum); // Update maxi if the current sum is greater

            // If the current sum is less than 0, reset it to 0
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxi;
    }
};