class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n =  nums.size();
        int left = 0;
        int sum = 0;
        int minWindow = INT_MAX;
        for(int right = 0; right < n; right++){
            sum += nums[right];
            if(sum >= target){
                while(sum >= target){
                    minWindow =  min(minWindow, right - left + 1);
                    sum -= nums[left];
                    left++;
                }
            }
        }
        return (minWindow == INT_MAX) ? 0 : minWindow;
    }
};