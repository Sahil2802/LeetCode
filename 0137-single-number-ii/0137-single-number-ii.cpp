class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // ones: tracks bits that have appeared exactly once (mod 3)
        // twos: tracks bits that have appeared exactly twice (mod 3)
        // When a bit appears 3 times, it's cleared from both ones and twos
        int ones = 0, twos = 0;
        
        for(int x : nums){
            // Update ones: XOR with current number to toggle the bit
            // Then AND with ~twos to clear bits that have appeared twice
            // This ensures bits appearing for the 3rd time don't stay in ones
            ones = (ones ^ x) & (~twos); 
            
            // Update twos: XOR with current number to toggle the bit
            // Then AND with ~ones to clear bits that are currently in ones
            // This moves bits from ones to twos on their second appearance
            twos = (twos ^ x) & (~ones); 
        }
        
        // After processing all numbers, ones contains the bits of the 
        // number that appeared exactly once (all others appeared 3 times)
        return ones;
    }
};