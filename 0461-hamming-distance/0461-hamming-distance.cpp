class Solution {
public:
    int hammingDistance(int x, int y) {
        // XOR operation: gives 1 where bits differ, 0 where they match
        int ans = x ^ y;
        
        int count = 0; // counts the number of differing bit positions
        
        // Brian Kernighan's algorithm: count set bits efficiently
        while (ans) {
            ans &= (ans - 1);  // removes rightmost 1-bit
            count++;                        // each 1-bit represents a position where bits differ
        }
        
        return count;
    }
};