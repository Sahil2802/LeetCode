class Solution {
public:
    int fib(int n) {
        // Initialize variables for the two previous Fibonacci numbers
        int prev1 = 1; // Represents fib(i-1)
        int prev2 = 0; // Represents fib(i-2)
        int curr;      // Will store the current Fibonacci number

        // Handle the case when n is 0
        if (n == 0) return 0;

        // Iterate from 2 to n, updating prev1 and prev2 each time
        for(int i = 2; i <= n; i++){
            // Current Fibonacci number is the sum of the previous two
            curr = prev1 + prev2;
            // Update prev2 to the previous prev1
            prev2 = prev1;
            // Update prev1 to the current value
            prev1 = curr;
        }

        // If n is 1, the loop doesn't run and prev1 already has the answer (fib(1) = 1)
        return prev1;        
    }
};