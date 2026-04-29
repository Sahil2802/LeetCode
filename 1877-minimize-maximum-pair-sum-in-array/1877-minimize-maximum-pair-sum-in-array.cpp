class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int l = 0, r = n-1;
        int sum = 0;
        int result = 0;
        while(l < r){
            sum = nums[l] + nums[r];
            result = max(result, sum);
            l++;
            r--;
        }
        return result;
    }
};