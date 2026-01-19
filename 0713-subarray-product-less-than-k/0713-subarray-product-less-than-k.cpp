class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // Edge case: if k <= 1, no valid subarray exists (all nums are positive)
        if (k <= 1) return 0;
        
        int n = nums.size();
        int left = 0;                  // Left boundary of sliding window
        long long prod = 1;            // Current product of window elements
        int count = 0;                 // Total count of valid subarrays
        
        // Variable-size sliding window: expand by moving right pointer
        for(int right = 0; right < n; right++){
            // Add current element to window by multiplying
            prod *= nums[right];
            
            // Shrink window from left while product >= k
            // This ensures window always maintains product < k
            while(prod >= k){
                // Remove leftmost element from product
                prod /= nums[left];
                left++;
            }
            
            // Note: All subarrays ending at 'right' within [left, right] are valid
            // Count = right - left + 1
            // Example: if window is [a, b, c] at indices [left=0, right=2]
            // Valid subarrays: [c], [b,c], [a,b,c] → 3 subarrays = (2-0+1)
            count += right - left + 1;
        }
        
        return count;
    }
};