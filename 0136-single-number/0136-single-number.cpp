class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        int xorRes = 0;
        for(int i = 0; i < n; i++){
            xorRes = xorRes ^ nums[i]; 
        }
        return xorRes;
    }
};