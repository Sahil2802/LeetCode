class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        int n = name.size();
        int t = typed.size();

        while (j < t) {
            if (i < n && name[i] == typed[j]) {
                // Characters match: this is a correct character from name.
                // Advance both pointers to check the next characters.
                i++;
                j++;
            } else if (j > 0 && typed[j] == typed[j - 1]) {
                // Characters don't match, but typed[j] is the same as typed[j-1].
                // This means typed[j] is a long press of the previous character.
                j++;
            } else {
                // Characters don't match and typed[j] is not a long press
                return false;
            }
        }

        // Successfully consumed all of typed.
        // Check if we also consumed all of name.
        // If i == n, every character in name was matched.
        // If i < n, there are leftover characters in name that weren't typed.
        return i == n;
    }
};