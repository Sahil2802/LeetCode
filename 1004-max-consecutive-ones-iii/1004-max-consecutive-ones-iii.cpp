class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;       // Maximum length of valid subarray
        int zeroCount = 0;    // Count of zeros in current window
        int right = 0, left = 0;  // Two pointers for sliding window
        
        // Expand window by moving right pointer
        while(right < n){
            // If current element is 0, increment zero count
            if(nums[right] == 0) zeroCount++;
            
            // Shrink window if zero count exceeds k
            while(zeroCount > k){
                // If left element is 0, decrement zero count
                if(nums[left] == 0){
                    zeroCount--;
                }
                // Move left pointer to shrink window
                left++;
            }
            
            // Update maximum length with current valid window size
            maxLen = max(maxLen, right - left + 1);
            
            // Move right pointer to expand window
            right++;
        }
        
        return maxLen;
    }
};