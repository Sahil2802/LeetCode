class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n - 1;

        // Standard two-pointer palindrome check
        while (l < r) {
            if (s[l] != s[r]) {
                // Mismatch found: try deleting either the left or right character,
                return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
            }
            l++;
            r--;
        }
        return true; // no mismatch found, already a palindrome with 0 deletions
    }

private:
    // Plain two-pointer palindrome check, no deletions allowed
    bool isPalindrome(string &s, int left, int right) {
        while (left <= right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};