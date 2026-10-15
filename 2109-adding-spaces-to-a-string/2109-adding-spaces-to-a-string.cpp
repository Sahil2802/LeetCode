class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size();
        int m = spaces.size();
        string res = "";
        res.reserve(s.size() + spaces.size());   // final length known up front, avoids reallocations

        int j = 0; // j = pointer into spaces
        for(int i = 0; i < n; i++){ // i = current index in s
            if(j < m && i == spaces[j]){
                res += ' '; // space goes before s[i]
                j++;
            }
            res += s[i];// always append the current character
        }
        return res;
    }
};