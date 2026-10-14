class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 1;   // i = current index, j = next index (always i + 1)

        // Step 1: apply operations sequentially, left to right
        while(i < n - 1){
            if(nums[i] == nums[i+1]){
                nums[i] = nums[i]*2;   // double the current element
                nums[j] = 0;           // zero out the next element
            }
            i++;
            j++;
        }

        // Step 2: shift all zeros to the end (stable, in place)
        for(int k = 0; k < n; k++){
            if(nums[k] == 0){
                for(int l = k + 1; l < n; l++){
                    if(nums[l] != 0){
                        swap(nums[k], nums[l]);
                        break;
                    }
                }
            }
        }
        return nums;
    }
};