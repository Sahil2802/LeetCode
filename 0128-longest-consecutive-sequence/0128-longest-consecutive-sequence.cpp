class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int lastSmaller = INT_MIN;
        int cnt = 0;
        int longest = 0;
        for (int i=0; i<n; i++){
            if (nums[i] - 1 == lastSmaller){
                cnt += 1;
                lastSmaller = nums[i];
            }
            else if (nums[i] != lastSmaller){
                cnt = 1;
                lastSmaller = nums[i];
            }
            longest = max(cnt, longest);
        }
        return longest;

    }
};