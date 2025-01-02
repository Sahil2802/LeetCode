class Solution {
public:
    int myAtoi(string s) {
        int n = s.size(); // Get the size of the input string
        long long result = 0; // Initialize result to 0
        int i = 0; // Initialize index to 0
        int sign = 1; // Initialize sign to 1 (positive)

        // Step 1: Ignore leading whitespace
        while (i < n && s[i] == ' ') {
            i++; // Increment index to skip whitespace
        }

        // Step 2: Determine the sign
        if (i < n && s[i] == '+') {
            i++; // Increment index if '+' is found
        } else if (i < n && s[i] == '-') {
            sign = -1; // Set sign to -1 if '-' is found
            i++; // Increment index
        }

        // Step 3: Read the integer part
        while (i < n && (s[i] >= '0' && s[i] <= '9')) {
            int digit = s[i] - '0'; // Convert character to digit

            // Step 4: Handle overflow
            // Check if result will overflow when multiplied by 10 || If result is at the threshold(equal to INT_MAX) where adding a large digit would cause an overflow.
            if (result > (INT_MAX / 10) || (result == (INT_MAX / 10) && digit > 7)) {
                // Return INT_MAX if positive overflow, INT_MIN if negative overflow
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit; // Update result with the new digit
            i++; // Increment index to move to the next character
        }

        // Apply the sign to the result
        return sign * result;
    }
};