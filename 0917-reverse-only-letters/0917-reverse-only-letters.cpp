class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while (i <= j) {
            if (isalpha(s[i]) && isalpha(s[j])) {
                // both are letters: swap and move both pointers inward
                swap(s[i], s[j]);
                i++;
                j--;
            } else if (!isalpha(s[i])) {
                // left char isn't a letter, skip it
                i++;
            } else if (!isalpha(s[j])) {
                // right char isn't a letter, skip it
                j--;
            }
        }
        return s;
    }
};
