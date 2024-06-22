class Solution {
public:
    void solve(vector<vector <int>> &ans, vector<int> &temp, vector<int>& nums){
        // base case : if tempSize is same as the nums size current permutation is completed
        if(temp.size() == nums.size()){
            ans.push_back(temp); // add the current permutation to the ans
            return; // return the curr recursive call
        }

        for(int i = 0; i < nums.size(); i++){
            // if the current element is already in temp, skip the element in the iteration.
            if(find(temp.begin(), temp.end(), nums[i]) != temp.end()){
                continue;
            }
            // Add the current element nums[i] to temp
            temp.push_back(nums[i]);
            // recursive call with the updated temp
            solve(ans, temp, nums);
            // Backtrack: remove the last element added
            temp.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector <int>> ans;
        vector<int> temp; // temporary vector to store the curr permutations
        solve(ans, temp, nums);
        return ans;
    }
};