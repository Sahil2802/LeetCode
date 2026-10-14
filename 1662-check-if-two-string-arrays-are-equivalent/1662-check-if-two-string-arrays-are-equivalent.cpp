class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j = 0;  // array indices
        int ch1 = 0, ch2 = 0;  // character indices within current strings
        
        // Traverse both arrays character by character
        while (i < word1.size() && j < word2.size()) {
            // Compare current characters from word1[i] and word2[j]
            if (word1[i][ch1] != word2[j][ch2]) {
                return false;
            }
            
            // Move to next character in word1[i]
            ch1++;
            if (ch1 == word1[i].size()) {
                // Reached end of current string in word1, move to next array element
                i++;
                ch1 = 0;
            }
            
            // Move to next character in word2[j]
            ch2++;
            if (ch2 == word2[j].size()) {
                // Reached end of current string in word2, move to next array element
                j++;
                ch2 = 0;
            }
        }
        
        // Both arrays should be fully consumed at the same time
        return i == word1.size() && j == word2.size();
    }
};