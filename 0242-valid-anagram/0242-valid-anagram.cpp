class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        if (s.size() != t.size()){
            return false;
        } 

        for (auto c : s){
            map[c]++;
        }
        for (auto c : t){
            map[c]--;
        }

        for (auto c : map){
            if(c.second != 0){
                return false;
            }
        }
        return true;
    }
};