class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            // Odd-length palindromes: center is a single character at i
            count += countPalindrome(s, i, i);
            // Even-length palindromes: center is between i and i+1
            count += countPalindrome(s, i, i + 1);
        }

        return count;
    }

private:
    // Expand outward from (left, right) while characters match,
    // counting each valid palindromic substring found along the way
    int countPalindrome(string &s, int left, int right) {
        int count = 0;

        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            count++;   // current (left, right) span is a palindrome
            left--;    // expand outward
            right++;
        }
        return count;
    }
};