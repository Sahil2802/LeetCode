class Solution {
public:
    int climbStairs(int n) {
        // Base cases: If there is 1 or 2 steps, return n
        if (n <= 2) return n;

        // Initialize variables for the previous two results
        int prev1 = 2; // Number of ways to reach step 2
        int prev2 = 1; // Number of ways to reach step 1
        int curr;      // Will store the current number of ways

        // Iterate from step 3 to n
        for(int i = 3; i <= n; i++){
            // Current ways is the sum of the previous two
            curr = prev1 + prev2;
            // Update prev2 and prev1 for the next iteration
            prev2 = prev1;
            prev1 = curr;
        }
        // After the loop, prev1 holds the number of ways to climb n steps
        return prev1;
    }
};    