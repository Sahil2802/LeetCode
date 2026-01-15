class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        
        // If string is shorter than 10 characters, no 10-letter sequences exist
        if(n < 10) return {};

        // Hash map to track frequency of each 10-character substring
        unordered_map<string, int> freq;
        vector<string> ans;
        
        // Sliding window: extract all substrings of length 10
        // Stop at n-10 to ensure we have exactly 10 characters remaining
        for(int i = 0; i <= n - 10; i++){
            // Extract substring starting at index i with length 10
            string sub = s.substr(i, 10);
            
            // Increment frequency count for this substring
            freq[sub]++;

            // Add to result only when frequency becomes exactly 2
            // This ensures we don't add duplicates to the answer
            // (sequences appearing 3+ times won't be added again)
            if(freq[sub] == 2){
                ans.push_back(sub);
            }
        }
        
        return ans;
    }
};