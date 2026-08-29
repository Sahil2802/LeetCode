class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();

        int prev = 0;   // length of the previous completed run
        int curr = 1;   // length of the current run being built (s[0] starts it)
        int result = 0;

        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                // still the same character, current run grows
                curr++;
            } else {
                // run just broke: s[i] differs from s[i-1]
                // the boundary between prev-run and just-finished curr-run
                result += min(curr, prev);

                // the just-finished run becomes the new "previous" run
                prev = curr;
                // start a new run of length 1 at position i
                curr = 1;
            }
        }

        // the loop only adds to result when a run breaks,
        // so the very last run's contribution is never added inside the loop
        // add it once after the loop ends
        return result + min(curr, prev);
    }
};