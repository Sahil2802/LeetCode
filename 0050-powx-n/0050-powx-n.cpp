class Solution {
public:
    double myPow(double x, int n) {
        // Step 1: Handle the case when n is 0
        // Any number raised to the power of 0 is 1
        if (n == 0) return 1.0;

        // Step 2: Convert n to long long to handle edge cases
        // This is necessary to handle the case when n is INT_MIN
        long long N = n;

        // Step 3: Handle negative powers
        // If n is negative, we need to invert x and make N positive
        if (n < 0) {
            x = 1 / x; // Invert x
            N = -N;    // Make N positive
        }

        // Step 4: Initialize result to 1
        // This will hold the final result of x raised to the power N
        double result = 1.0;

        // Step 5: Use binary exponentiation to calculate the power
        // Iterate while N is greater than 0
        while (N > 0) {
            // If N is odd, multiply result by x and decrement N
            if (N % 2 == 1) {
                result *= x;
                N -= 1;
            }
            // If N is even, square x and halve N
            else {
                x *= x;
                N /= 2;
            }
        }

        // Return the final result
        return result;
    }
};