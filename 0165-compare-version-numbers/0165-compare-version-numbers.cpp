class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m = version1.size();
        int n = version2.size();
        int i = 0, j = 0;

        // Keep going while either string still has revisions left
        while (i < m || j < n) {
            long rev1 = 0, rev2 = 0;

            // Extract next revision number from version1
            while (i < m && version1[i] != '.') {
                rev1 = rev1 * 10 + (version1[i] - '0'); // build number digit by digit
                i++;
            }
            i++; // skip the '.' separator

            // Extract next revision number from version2
            while (j < n && version2[j] != '.') {
                rev2 = rev2 * 10 + (version2[j] - '0');
                j++;
            }
            j++; // skip the '.' separator

            // Compare current revisions
            // if one string ran out, its rev stays 0 (treated as missing revision)
            if (rev1 < rev2) return -1;
            if (rev1 > rev2) return 1;
        }

        return 0; // all revisions matched
    }
};