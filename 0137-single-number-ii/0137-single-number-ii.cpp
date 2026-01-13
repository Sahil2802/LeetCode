class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0; 
        
        // Check all 32 bit positions (since nums[i] is in range [-2^31, 2^31-1])
        for(int bit = 0; bit < 32; bit++){
            int count = 0;  // Count how many numbers have this bit set
            
            // Count occurrences of current bit across all numbers
            for(int x : nums){
                // Check if bit at position 'bit' is set in x
                if((x >> bit) & 1){
                    count++;
                }
            }
            
            // If count is not divisible by 3, this bit belongs to the single number
            // (Numbers appearing 3 times contribute bits in multiples of 3)
            if(count % 3 != 0){
                ans = ans | (1 << bit);  // Set this bit in the answer
            }
        }
        return ans;
    }
};