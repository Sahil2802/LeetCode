class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        vector <int> charIdx(128, -1);
        int left = 0, right = 0;

        while(right < n){
            if (charIdx[s[right]] != -1){
                if (charIdx[s[right]] >= left){
                    left = charIdx[s[right]] + 1;
                }
            }
            charIdx[s[right]] = right;
            int length = right - left + 1;
            maxLength = max(length, maxLength);
            right++;

        }
        return maxLength;
    }
};