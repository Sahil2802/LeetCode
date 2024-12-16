class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size(); 
        int l = 0, r = n - 1; // Initialize two pointers, l (left) and r (right)
        
        // Loop until the two pointers meet in the middle
        while (l < r) {
            swap(s[l], s[r]); // Swap the characters at positions l and r
            l++; 
            r--; 
        }
    }
};
