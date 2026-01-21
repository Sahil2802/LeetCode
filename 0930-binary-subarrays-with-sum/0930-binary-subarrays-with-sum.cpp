class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // KEY TRICK: Count subarrays with exact sum using "at most" technique
        // subarrays(sum == goal) = subarrays(sum <= goal) - subarrays(sum <= goal-1)
        // 
        // Example: goal = 2, nums = [1,0,1,0,1]
        // atMost(2) counts: sum=0, sum=1, sum=2
        // atMost(1) counts: sum=0, sum=1
        // Difference gives only: sum=2 (exactly what we want)
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
    
    // Helper: Count subarrays with sum AT MOST 'goal'
    int atMost(vector<int> &nums, int goal){
        // Edge case: negative goal means no valid subarrays (all elements non-negative)
        if(goal < 0) return 0;
        
        int n = nums.size();
        int left = 0;                  // Left boundary of sliding window
        int sum = 0;                   // Current window sum
        int count = 0;                 // Total count of valid subarrays
        
        // Variable-size sliding window: expand by moving right pointer
        for(int right = 0; right < n; right++){
            // Add current element to window sum
            sum += nums[right];
            
            // Shrink window from left while sum exceeds goal
            // This ensures window maintains sum <= goal
            while(sum > goal){
                sum -= nums[left];
                left++;
            }
            
            // Count all subarrays ending at 'right' with sum <= goal
            // All subarrays in window [left, right] are valid
            // Count = right - left + 1
            count += right - left + 1;
        }
        
        return count;
    }
};