class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> res(n, pivot);   // pre-filled with pivot, so the middle is already correct

        // Loop 1: smaller values, scan left to right, fill from the front
        int lo = 0;                  // lo = next free slot from the left
        for(int i = 0; i < n; i++){
            if(nums[i] < pivot){
                res[lo] = nums[i];   // place the smaller value in order
                lo++;                // advance only when a value is placed
            }
        }

        // Loop 2: larger values, scan right to left, fill from the back
        int hi = n - 1;              // hi = next free slot from the right
        for(int j = n-1; j >= 0; j--){
            if(nums[j] > pivot){
                res[hi] = nums[j];   // last large element lands in the last slot, keeping original order
                hi--;                // move left for the next larger value
            }
        }

        return res;                  // untouched slots in the middle remain pivot
    }
};