class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(); // Get the size of the greed array
        int m = s.size(); // Get the size of the cookieSize array

        // Sort the greed factors in ascending order to try and satisfy the least greedy children first
        sort(g.begin(), g.end());
        
        // Sort the cookie sizes in ascending order to use the smallest cookies first
        sort(s.begin(), s.end());

        // Initialize a pointer for the greed array
        int greedIndex = 0;
        
        // Initialize a pointer for the cookieSize array
        int cookieIndex = 0;

        // Iterate while there are cookies and children left in the array
        while(greedIndex < n && cookieIndex < m) {
            // If the current cookie can satisfy the current child's greed
            if(g[greedIndex] <= s[cookieIndex]) {
                // Move to the next child, as the current child is satisfied
                greedIndex++;
            }
            // Always move to the next cookie whether the current child was satisfied or not
            cookieIndex++;
        }
        
        // The value of greedIndex at the end of the loop represents the number of children that were satisfied
        return greedIndex;
    }
};