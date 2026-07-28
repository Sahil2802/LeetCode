class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> squared(n);
        for(int i = 0; i < n; i++){
            squared[i] = nums[i]*nums[i];
        }
        sort(squared.begin(), squared.end());
        return squared;
    }

};