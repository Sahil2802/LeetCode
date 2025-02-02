class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Get the sizes of the greed factor array and the cookie size array
        int n = g.size();
        int m = s.size();
        
        // Sort both arrays to facilitate the greedy approach
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        // Initialize two pointers for the greed factor array (l) and the cookie size array (r)
        int l = 0, r = 0;
        
        // Iterate through both arrays until we reach the end of either array
        while(l < n && r < m){
            // If the current cookie can satisfy the current child's greed factor
            if(g[l] <= s[r]){
                // Move to the next child
                l++;
            }
            // Move to the next cookie
            r++;
        }
        
        // The number of content children is the number of children we have satisfied
        return l;
    }
};