class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1; // pointer at end of s
        int j = t.size() - 1; // pointer at end of t

        while (i >= 0 || j >= 0) {
            // Skip backspaced characters in s (process from the back)
            int skipS = 0;
            while (i >= 0 && (s[i] == '#' || skipS > 0)) {
                if (s[i] == '#') skipS++;  // found a backspace, need to skip one more char
                else skipS--;               // this char got backspaced, consume it
                i--;
            }

            // Skip backspaced characters in t (same logic)
            int skipT = 0;
            while (j >= 0 && (t[j] == '#' || skipT > 0)) {
                if (t[j] == '#') skipT++;
                else skipT--;
                j--;
            }

            // Both pointers landed on a valid (non-backspaced) character
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j]) return false; // mismatch, strings differ
            }
            // One string still has a valid char, the other ran out -> length mismatch
            else if (i >= 0 || j >= 0) return false;

            // Move both pointers past the compared characters
            i--;
            j--;
        }
        return true; // all characters matched till both strings exhausted
    }
};