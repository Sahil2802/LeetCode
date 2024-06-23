class Solution {
public:
    void solve(int i, vector<vector<int>> &ans, vector<int> &temp, vector<int>& nums){
        if(i >= nums.size()){
            ans.push_back(temp);
            return;
        }

        // take ith element
        temp.push_back(nums[i]);
        solve(i + 1, ans, temp, nums);
        // not take ith element
        temp.pop_back();
        solve(i + 1, ans, temp, nums);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> ans;
       vector<int> temp;
       solve(0, ans, temp, nums);
       return ans;
    }
};