class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int l = 0, r = 0; // Initialize two pointers, l (left) and r (right)

        // Iterate over each character in the input string
        while (r <= n) {
            // If we find a space or reach the end of the string, reverse the word
            if (r == n || s[r] == ' ') {
                reverse(s.begin() + l, s.begin() + r); // Reverse the current word range being [l, r)
                l = r + 1; // Move the left pointer to the start of the next word
            }
            r++; // Move the right pointer to the next character
        }
        return s;
    }
};
