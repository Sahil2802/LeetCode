class Solution {
public:
    void solve(vector<vector <int>> &ans, vector<int> &temp, vector<int>& nums){
        // base case
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(find(temp.begin(), temp.end(), nums[i]) != temp.end()){
                continue;
            }
            temp.push_back(nums[i]);
            solve(ans, temp, nums);
            temp.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector <int>> ans;
        vector<int> temp;
        solve(ans, temp, nums);
        return ans;
    }
};