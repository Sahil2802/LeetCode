class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int greedIndex = 0;
        int cookieIndex = 0;

        while(greedIndex < n && cookieIndex < m){
            if(g[greedIndex] <= s[cookieIndex]){
                greedIndex++;
            }
            cookieIndex++;
        }
        return greedIndex;
    }
};