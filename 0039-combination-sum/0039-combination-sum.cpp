class Solution {
public:
    void solve(int i, int target, vector<int> &arr, vector<vector<int>> &ans, vector <int> &temp){
        // Base Case
        // if target becomes zero, then we found a possible combination.
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        // if target becomes less than zero, then we simply return because it is no
        if (target < 0) return;
        if(i == arr.size()) return;

        // Pick
        temp.push_back(arr[i]);
        solve(i, target - arr[i], arr, ans, temp);
        // Not pick
        temp.pop_back();
        solve(i + 1, target, arr, ans, temp);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector <int> temp;
        solve(0, target, candidates, ans, temp);
        return ans;
    }
};