class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n - 1; // Initialize two pointers, l (left) and r (right)

        // Loop until the two pointers meet in the middle
        while (l < r) { 
            // Skip non-alphanumeric characters from the left
            if (!isalnum(s[l])) { 
                l++;
            }
            // Skip non-alphanumeric characters from the right
            else if (!isalnum(s[r])) { 
                r--;
            }
            // If characters do not match, return false
            else if (tolower(s[l]) != tolower(s[r])) { 
                return false; 
            }
            // If characters match, move the pointers towards the center
            else { 
                l++;
                r--;
            }
        }
        return true; // If all characters match, return true
    }
};