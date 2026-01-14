class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Step 1: XOR all numbers to get xor_result = a ^ b
        // (all duplicate numbers cancel out, leaving only the two unique numbers)
        long long xorRes = 0;
        for(int x : nums) xorRes ^= x;

        // Step 2: Find any bit position where a and b differ
        // xorRes & (-xorRes) isolates the rightmost set bit in xorRes
        // This gives us a bit that is 1 in either a or b, but not both
        long long bitDiff = xorRes & (-xorRes);
        
        // Step 3: Partition all numbers into two groups based on bitDiff
        // Group 1: numbers with bitDiff set (contains one unique number 'a')
        // Group 2: numbers without bitDiff set (contains other unique number 'b')
        int a = 0, b = 0;
        for(int x : nums) {
            // If the bit at bitDiff position is set in x, XOR with a
            if(bitDiff & x) a ^= x;
            // Otherwise, XOR with b
            else b ^= x;
        }
        
        // Return both unique numbers
        return {a, b};
    }
};