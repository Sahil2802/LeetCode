class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector <int> hash1(26, 0), hash2(26, 0);
        int s1len = s1.size(), s2len = s2.size();
        // fill the frequency map for s1
        for (int i = 0; i < s1len; i++){
            hash1[s1[i] - 'a']++;
        }
        int left = 0, right = 0;
        while(right < s2len){
            // Add the current character to the 2nd string's frequency map
            hash2[s2[right] - 'a']++;

            // If the window size exceeds n, remove the leftmost character from the window
            if(right >= s1len){
                hash2[s2[left] - 'a']--;
                left++;
            }
            // Check if the current window matches the frequency map of s1
            if(hash1 == hash2) return true;

            // Move the right pointer
            right++;
        }
        return false;
    }
};