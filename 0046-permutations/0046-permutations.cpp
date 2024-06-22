class Solution {
public:
    unordered_set <int> st;
    void solve(vector<vector <int>> &ans, int ind, vector<int>& nums){
        // base case : if index reaches the end append the permutation and return
        if(ind == nums.size()){
            ans.push_back(nums); // add the current permutation to the ans
            return; // return the curr recursive call
        }   

        for(int i = ind; i < nums.size(); i++){
            swap(nums[ind], nums[i]); // Swap the curr element with the element at the curr index
            solve(ans, ind + 1, nums);
            swap(nums[ind], nums[i]); // Backtrack-> Swap back the elements
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector <int>> ans; 
        solve(ans, 0, nums);
        return ans;
    }
};