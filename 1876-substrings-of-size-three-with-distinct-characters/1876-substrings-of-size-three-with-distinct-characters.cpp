class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        int count = 0;
        
        // Iterate through all possible substrings of length 3
        // Stop at n-3 to avoid going out of bounds (we need 3 characters)
        for(int i = 0; i <= n - 3; i++){
            // Extract the three consecutive characters
            int a = s[i], b = s[i+1], c = s[i+2];
            
            // A "good substring" has all three characters distinct
            // Check all three pairwise comparisons
            if(a != b && b != c && c != a){
                count++;
            } 
        }
        
        return count;
    }
};