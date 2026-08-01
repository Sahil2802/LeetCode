class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(); // length of haystack
        int n = needle.size();   // length of needle

        // i <= m - n ensures there's enough room left in haystack to search 
        for (int i = 0; i <= m - n; i++) {
            int j = 0; // pointer into needle

            // Try to match needle starting at position i in haystack
            while (j < n && haystack[i + j] == needle[j]) {
                j++;
            }

            // j reached n means every character of needle matched
            if (j == n) return i;
        }

        return -1; // no match found anywhere
    }
};