class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();

        // Two pointers:
        // i starts from left, j starts from right.
        int i = 0, j = n - 1;

        // Continue until the pointers cross.
        while (i < j) {
            // Case 1: both characters are vowels -> swap and move both pointers.
            if (isVowel(s[i]) && isVowel(s[j])) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            // Case 2: left is vowel, right is not -> move right pointer left.
            else if (isVowel(s[i])) {
                j--;
            }
            // Case 3: right is vowel, left is not -> move left pointer right.
            else if (isVowel(s[j])) {
                i++;
            }
            // Case 4: neither is vowel -> move both pointers inward.
            else {
                i++;
                j--;
            }
        }

        // String with vowels reversed in-place.
        return s;
    }

    // Helper function to check if a character is a vowel (both lowercase and uppercase).
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            return true;
        }
        return false;
    }
};