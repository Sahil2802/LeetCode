class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int n = nums.size();
        for (int i=0; i<n; i++){
            int num = nums[i];
            int numLeft = target - num;
            if(map.find(numLeft) != map.end()){
                return {map[numLeft], i};
            } 
            // assign the index to the element map[10] = 0.
            map[num] = i;
        }
        return {-1, -1};
    }
};