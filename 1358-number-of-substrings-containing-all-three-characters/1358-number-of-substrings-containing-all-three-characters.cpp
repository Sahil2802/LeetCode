class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        // freq[0] -> count of 'a'
        // freq[1] -> count of 'b'
        // freq[2] -> count of 'c'
        vector<int> freq(3, 0);

        long long count = 0;  // total valid substrings
        int left = 0;         // left pointer of sliding window
        int right = 0;        // right pointer of sliding window

        // expand window using right pointer
        while (right < n) {

            // include current character in window
            freq[s[right] - 'a']++;

            // while window contains at least one 'a', 'b', and 'c'
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {

                // all substrings starting from left and ending at
                // any position from right to n-1 will be valid
                // so we add (n - right)
                count += (n - right);

                // shrink window from left to find next possible valid window
                freq[s[left] - 'a']--;
                left++;
            }

            // move right pointer forward to expand window
            right++;
        }

        return (int)count;
    }
};