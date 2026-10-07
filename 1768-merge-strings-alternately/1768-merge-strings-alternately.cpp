class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int i = 0, j = 0;
        
        string ans = "";

        // Keep looping while at least one string has characters left
        while (i < n || j < m) {
            // If word1 has characters remaining, add the next one
            if (i < n) {
                ans.push_back(word1[i]);
                i++;
            }
            // If word2 has characters remaining, add the next one
            if (j < m) {
                ans.push_back(word2[j]);
                j++;
            }
        }

        return ans;
    }
};