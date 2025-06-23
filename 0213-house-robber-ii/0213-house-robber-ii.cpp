class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 0) return 0;
        if(n == 1) return nums[0];
        
        int firstToSecondLast = helper(0, n-2, nums);
        int secondToLast = helper(1, n-1, nums);

        return max(firstToSecondLast, secondToLast);
    }

    int helper(int start, int end, vector<int> &nums){
        int len = end - start + 1; 
        if (len == 1) return nums[start];

        vector<int> dp(len, 0);

        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);


        for(int i = 2; i < len; i++){
            int pick = nums[start + i] + dp[i - 2];
            int notPick = dp[i - 1];
            dp[i] = max(pick, notPick);
        }

        return dp[len-1];
    }
};