class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        // start at 1 since each step compares with the previous element
        for(int i = 1; i < n; i++){
            // even index: should be a peak (bigger than previous)
            if(i % 2 == 0){
                // previous is bigger, so swap to push the larger value into the even slot
                if(nums[i] < nums[i-1]){
                    swap(nums[i], nums[i-1]);
                }
            }
            // odd index: should be a valley (smaller than previous)
            else{
                // previous is smaller, so swap to push the smaller value into the odd slot
                if(nums[i] > nums[i-1]){
                    swap(nums[i], nums[i-1]);
                }
            }
        }
        return nums;
    }
};