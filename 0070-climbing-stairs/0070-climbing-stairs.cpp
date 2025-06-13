class Solution {
public:
    int climbStairs(int n) {
        // Create a dp array of size n+1, initialized with -1
        // dp[i] will store the number of ways to reach step i
        vector<int> dp(n+1, -1);
        return helper(n, dp);
    }

private:
    int helper(int n, vector<int> &dp){
        // Base cases: If n is 1 or 2, return n (1 way for 1 step, 2 ways for 2 steps)
        if(n <= 2) return n;

        // If already computed, return the stored value
        if(dp[n] != -1) return dp[n];

        // Recursively compute the result and store it in dp[n]
        // Number of ways to reach step n is the sum of ways to reach (n-1) and (n-2)
        return dp[n] = helper(n-1, dp) + helper(n-2, dp);
    }
};