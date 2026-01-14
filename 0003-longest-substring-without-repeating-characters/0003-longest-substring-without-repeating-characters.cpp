class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLength = 0;
        
        // Track the last seen index of each character (ASCII 256 characters)
        // Initialize all positions to -1 (not seen yet)
        vector<int> lastSeen(256, -1);
        
        // Sliding window: l = left pointer, r = right pointer
        int l = 0, r = 0;
        
        while(r < n){
            // Example: "abcabcd"
            // When r points to second 'a', lastSeen['a'] = 0, l = 0
            // We need to move l to position 1 (after the first 'a')
            
            // If current character was seen before AND is within current window
            if(lastSeen[s[r]] >= l){
                // Move left pointer to just after the last occurrence
                // This removes the duplicate from the window
                l = lastSeen[s[r]] + 1;
            }
            
            // Update the last seen position of current character
            lastSeen[s[r]] = r;
            
            // Calculate current window length and update maximum
            maxLength = max(maxLength, r - l + 1);
            
            // Expand the window to the right
            r++;
        }
        
        return maxLength;
    }
};