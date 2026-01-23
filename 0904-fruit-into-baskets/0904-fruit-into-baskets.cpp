class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> freq;
        int maxi = 0;
        int left = 0, right = 0;
        while(right < n){
            freq[fruits[right]]++;
            while(freq.size() > 2){
                freq[fruits[left]]--;
                if(freq[fruits[left]] == 0){
                    freq.erase(fruits[left]);
                }
                left++;
            }
            maxi = max(maxi, right - left + 1);
            right++;
        }
        return maxi;
    }
};