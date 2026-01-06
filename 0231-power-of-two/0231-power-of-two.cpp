class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Powers of 2 have exactly one bit set in binary representation
        // e.g., 1=0001, 2=0010, 4=0100, 8=1000, 16=10000
        
        // n & (n-1) removes the rightmost set bit
        // For powers of 2, this results in 0 (since only one bit is set)
        // Also check n > 0 to exclude negative numbers and zero
        
        if (n > 0 && (n & (n - 1)) == 0) {
            return true;
        }
        return false;
    }
};