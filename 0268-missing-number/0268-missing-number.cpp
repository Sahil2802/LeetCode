class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N = nums.size();
        int sum = N * (N + 1) / 2; // Sum of N natural numbers

        int s1 = 0; // Sum of all the elements of the array
        for(int i = 0; i < N; i++){
             s1 += nums[i];
        }

        int ans = sum - s1;
        return ans;
    }
};