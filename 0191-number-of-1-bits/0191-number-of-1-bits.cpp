class Solution {
public:
    int hammingWeight(int n) {
        int count = 0; // tracks the number of 1-bits found
        
        // Brian Kernighan's algorithm: each iteration removes one 1-bit
        while (n > 0) {
            n &= (n - 1);  // removes the rightmost 1-bit from n
            count++;       // increment since we removed (found) one 1-bit
        }
        
        // Total iterations = total number of 1-bits in original n
        return count;
    }
};