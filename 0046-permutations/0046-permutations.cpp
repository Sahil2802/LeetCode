class Solution {
public:
    unordered_set <int> st;
    void solve(vector<vector <int>> &ans, vector<int> &temp, vector<int>& nums){
        // base case : if tempSize is same as the nums size current permutation is completed
        if(temp.size() == nums.size()){
            ans.push_back(temp); // add the current permutation to the ans
            return; // return the curr recursive call
        }

        for(int i = 0; i < nums.size(); i++){
            // condition satisfied: If nums[i] is not found
            if(st.find(nums[i]) == st.end()){
                // Add the current element nums[i] to temp and in set
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                // recursive call with the updated temp
                solve(ans, temp, nums);
                // Backtrack: remove the last element added from temp and set
                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector <int>> ans; 
        vector<int> temp; // temporary vector to store the curr permutations
        solve(ans, temp, nums);
        return ans;
    }
};