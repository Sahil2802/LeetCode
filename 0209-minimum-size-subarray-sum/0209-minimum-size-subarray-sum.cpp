class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;                  // Left boundary of sliding window
        int sum = 0;                   // Current window sum
        int minWindow = INT_MAX;       // Track minimum window length found
        
        // Variable-size sliding window: expand by moving right pointer
        for(int right = 0; right < n; right++){
            // Add current element to window sum
            sum += nums[right];
            
            // When sum meets/exceeds target, try to shrink window from left
            if(sum >= target){
                // Keep shrinking window till the sum is greater than or equal to target
                // This greedy approach finds the smallest valid window ending at 'right'
                while(sum >= target){
                    // Update minimum window length with current window size
                    minWindow = min(minWindow, right - left + 1);
                    
                    // Remove leftmost element and shrink window
                    sum -= nums[left];
                    left++;
                }
            }
        }
        
        // Return 0 if no valid subarray found, otherwise return minimum length
        return (minWindow == INT_MAX) ? 0 : minWindow;
    }
};