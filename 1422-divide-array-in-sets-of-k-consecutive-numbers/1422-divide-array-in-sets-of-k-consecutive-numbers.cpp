class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Step 1: Check if total cards can be evenly divided into groups
        // If not divisible, it's impossible to form equal-sized groups
        if(n % k != 0) return false;

        // Step 2: Count frequency of each num value
        // Using unordered_map for O(1) average lookup
        unordered_map<int, int> freq;
        for(int num : nums) {
            freq[num]++;
        }

        // Step 3: Create min heap with all cards (including duplicates)
        // Min heap ensures we always process smallest available card first
        priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.end());
        
        // Step 4: Try to form consecutive groups starting from smallest card
        while(!minHeap.empty()){
            int start = minHeap.top();  // Get smallest card
            minHeap.pop();

            // Skip if this card value has already been used in previous groups
            if(freq[start] == 0) continue;

            // Try to form a group of 'k' consecutive cards starting from 'start'
            for(int i = 0; i < k; i++){
                int curr = start + i;  // Next consecutive card needed
                
                // If we don't have this consecutive card available, grouping fails
                if(freq[curr] == 0) return false;
                
                // Use one card of this value for the current group
                freq[curr]--;
            }
        }
        
        // All cards successfully grouped into consecutive sequences
        return true;
    }
};