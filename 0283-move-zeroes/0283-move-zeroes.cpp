class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> temp;
        // append all the non zero numbers in temp array
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                temp.push_back(nums[i]);
            }
        }

        int m = temp.size();
        // copy the elements of temp back to original array
        for(int i = 0; i < temp.size(); i++){
            nums[i] = temp[i];
        }

        // fill the rest of the cells with zero
        for(int i = m; i < nums.size(); i++){
            nums[i] = 0;
        }
    }
};