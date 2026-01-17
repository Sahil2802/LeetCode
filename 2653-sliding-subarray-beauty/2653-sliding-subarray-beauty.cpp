class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        
        // Frequency array for negative numbers only (-50 to -1)
        // freq[i] stores count of number -i in current window
        int freq[51] = {0};
        
        int left = 0;  // Left boundary of sliding window
        
        // Right boundary of sliding window
        for(int right = 0; right < n; right++){
            // Add current element to window (only track negative numbers)
            if(nums[right] < 0){
                freq[-nums[right]]++;  // Store absolute value as index
            }
            
            // When window reaches size k, calculate beauty
            if(right - left + 1 == k){
                int count = 0;   // Count of elements processed so far
                int beauty = 0;  // Default beauty (if x-th smallest is non-negative)
                
                // Traverse from smallest negative to largest (-50 to -1)
                // freq[50] = count of -50, freq[1] = count of -1
                for(int i = 50; i >= 1; i--){
                    count += freq[i];  // Accumulate frequencies
                    
                    // If we've found x or more elements, i is the x-th smallest
                    if(count >= x){
                        beauty = -i;  // Convert back to negative value
                        break;
                    }
                }
                
                ans.push_back(beauty);
                
                // Slide window: remove leftmost element from frequency table
                if(nums[left] < 0){
                    freq[-nums[left]]--;
                }
                left++;  // Move window forward
            }
        }
        return ans;
    }
};