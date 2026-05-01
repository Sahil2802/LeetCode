class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();

        int l = 0, r = n - 1;

        // Shrink from both ends while the end characters match.
        while (l < r && s[l] == s[r]) {
            char ch = s[l];

            // Remove matching characters from the left.
            while (l < r && s[l] == ch) {
                l++;
            }

            // Remove matching characters from the right.
            while (l <= r && s[r] == ch) {
                r--;
            }
        }

        // Remaining length after all deletions.
        return (r - l + 1);
    }
};