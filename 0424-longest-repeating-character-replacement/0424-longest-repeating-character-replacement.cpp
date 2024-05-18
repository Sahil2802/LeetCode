class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l=0, r=0, maxf = 0;
        vector <int> charCount(26);
        int ans = 0;
        while (r<n){
            charCount[s[r] - 'A']++;
            maxf = max(maxf, charCount[s[r] - 'A']);
            // r - l + 1 = sliding window size
            if (r - l + 1 - maxf > k){
                charCount[s[l] - 'A']--;
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};