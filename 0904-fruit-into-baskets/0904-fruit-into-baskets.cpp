class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // Problem: Find maximum fruits you can collect with at most 2 types
        // Using Sliding Window with HashMap to track fruit types and counts
        
        int n = fruits.size();
        unordered_map<int, int> freq;  // Map to store fruit type and its frequency
        int maxi = 0;  // Store maximum fruits collected
        int left = 0, right = 0;  // Two pointers for sliding window
        
        // Expand window by moving right pointer
        while(right < n){
            // Add current fruit to the window
            freq[fruits[right]]++;
            
            // If more than 2 types, shrink window from left
            while(freq.size() > 2){
                // Remove leftmost fruit from window
                freq[fruits[left]]--;
                
                // If frequency becomes 0, remove the fruit type completely
                if(freq[fruits[left]] == 0){
                    freq.erase(fruits[left]);
                }
                
                // Move left pointer to shrink window
                left++;
            }
            
            // Update maximum length (number of fruits in valid window)
            maxi = max(maxi, right - left + 1);
            
            // Move right pointer to expand window
            right++;
        }
        
        return maxi;
    }
};