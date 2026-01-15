class Solution {
private:
    // Map each DNA character to a 2-bit value
    // A -> 00, C -> 01, G -> 10, T -> 11
    int getHash(char c){
        if(c == 'A') return 0;  // 00 in binary
        if(c == 'C') return 1;  // 01 in binary
        if(c == 'G') return 2;  // 10 in binary
        return 3;               // 11 in binary (T)
    }
    
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        
        // If string is shorter than 10 characters, no 10-letter sequences exist
        if(n < 10) return {};

        // OPTIMIZATION: Use integer hash instead of string to save memory
        // A char is 1 byte = 8 bits, so each character in a normal string takes 8 bits.
        // So a 10-length substring stores: 10 * 8 = 80 bits
        // With encoding, each DNA char uses only 2 bits (4 possibilities: A,C,G,T)
        // So a 10-length substring stores: 10 * 2 = 20 bits (fits in an int!)
        unordered_map<int, int> freq;
        vector<string> ans;

        int encode = 0;  // Rolling hash value representing current 10-char window
        
        // Mask with 20 bits set to 1: (1 << 20) - 1 = 0xFFFFF
        // Used to keep only the last 20 bits (last 10 DNA characters)
        int mask = (1 << 20) - 1;
        
        for(int i = 0; i < n; i++){
            // Rolling hash technique:
            // 1. Left shift encode by 2 bits to make room for new character
            // 2. OR with new character's 2-bit hash value
            // 3. AND with mask to keep only last 20 bits (10 characters)
            encode = ((encode << 2) | getHash(s[i])) & mask;

            // Once we have at least 10 characters (i >= 9)
            if(i >= 9){
                // Track frequency of this encoded 10-char sequence
                freq[encode]++;
                
                // Add to result only when frequency becomes exactly 2
                // Extract the actual substring for the answer
                if(freq[encode] == 2){
                    ans.push_back(s.substr(i - 9, 10));
                }
            }
        }
        
        return ans;
    }
};