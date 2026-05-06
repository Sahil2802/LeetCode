class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();

        vector<int> lastSeen(26, -1);
        for(int i = 0; i < n; i++){
            int idx = s[i] - 'a';
            lastSeen[idx] = i;
        }

        int i = 0;
        int start = 0;
        int end = 0;
        vector<int> result;
        while(i < n){
            end = max(lastSeen[s[i] - 'a'], end);
            if(i == end){
                result.push_back((end - start + 1));
                start = end + 1;
            }
            i++;
        }
        return result;
    }
};