class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        int n = words.size();
        
        // Iterate through each word in the array
        for (int i = 0; i < n; i++) {
            // Check if the current word is a palindrome
            if (isPalindrome(words[i])) {
                // Return the first palindromic string found
                return words[i];
            }
        }
        
        // No palindromic string found in the array
        return "";
    }

private:
    bool isPalindrome(string word) {
        int l = 0, r = word.size() - 1;
        
        // Two-pointer approach: compare characters from both ends moving inward
        while (l < r) {
            if (word[r] != word[l]) {
                // Characters don't match, not a palindrome
                return false;
            }
            // Move pointers toward the center
            l++;
            r--;
        }
        
        // All characters matched, it's a palindrome
        return true;
    }
};