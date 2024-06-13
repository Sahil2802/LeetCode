class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans(n); 
        // e.g nums = [1, 2, 3, 4]
        // calculate the prefix product in the same output array
        int prefix = 1;
        for(int i = 0; i < n; i++){
            ans[i] = prefix; // ans = [1, _, _, _] in 1st iteration
            prefix = prefix * nums[i];
        }
        
        // e.g ans = [1, 1, 2, 6] after prefix product calculation
        // Calculate the suffix product in the same output array
        int suffix = 1;
        for(int i = n-1; i >= 0; i--){
            ans[i] = ans[i] * suffix; // ans = [1, 1, 2, 6],  6 * 1 in the 1st iteration
            suffix = suffix * nums[i];
        }
        return ans;
    }
};