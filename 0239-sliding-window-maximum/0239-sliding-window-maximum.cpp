class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        
        // Deque stores indices (not values) in decreasing order of their values
        // Front of deque always contains index of maximum element in current window
        deque<int> dq;

        int left = 0;  // Left boundary of sliding window
        
        for(int right = 0; right < n; right++){
            // Maintain monotonic decreasing deque:
            // Remove all indices from back whose values are smaller than current element
            // (they can never be maximum in any future window since current is larger and newer)
            while(!dq.empty() && nums[dq.back()] < nums[right]){
                dq.pop_back();
            }
            
            // Add current index to the back of deque
            dq.push_back(right);
            
            // Remove indices that are out of current window bounds (left of 'left' pointer)
            // This ensures deque only contains indices within [left, right] window
            if(dq.front() < left){
                dq.pop_front();
            }

            // When window size reaches k, record the maximum and slide window
            if(right - left + 1 == k){
                // Front of deque contains index of maximum element in current window
                ans.push_back(nums[dq.front()]);
                
                // Slide window forward by moving left pointer
                left++;
            }
        }
        
        return ans;
    }
};