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

        // Step 2: shift all zeros to the end, O(n^2)
        for(int k = 0; k < n; k++){              // k = position being filled
            if(nums[k] == 0){                    // only act if this slot holds a zero
                for(int l = k + 1; l < n; l++){  // l = scans right for a non-zero
                    if(nums[l] != 0){
                        swap(nums[k], nums[l]);  // pull the first non-zero into slot k
                        break;                   // one swap per zero, move to next k
                    }
                }
            }
        }
        return nums;
    }
};