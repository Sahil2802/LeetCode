class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();

        int count = 0;
        for(int i = 0; i < n; i++){
            count += countPalindrome(s, i, i);
            count += countPalindrome(s, i, i+1);
        }        

        return count;
    }

private:
    int countPalindrome(string s, int left, int right){
        int count = 0;

        while(left >= 0 && right < s.size() && s[left] == s[right]){
            count++;
            left--;
            right++;
        }
        return count;
    }
};