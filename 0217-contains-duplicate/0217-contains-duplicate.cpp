// Using Hash map
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int, int> map;
        for (int i=0; i<n; i++){
            if (map[nums[i]] > 0){
            // return if the count of the element is more than 1. 
                return true;
            }
            map[nums[i]]++;
        }
        return false;
    }
};