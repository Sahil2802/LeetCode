class Solution {
public:
    // Find the Kth largest element using QuickSelect algorithm
    // Time Complexity: O(n) average, O(n²) worst case
    // Space Complexity: O(1)
    int findKthLargest(vector<int>& nums, int k) {
        int target = k - 1;              // Convert to 0-based index for kth largest
        int left = 0;                    // Left boundary of search range
        int right = nums.size() - 1;     // Right boundary of search range

        while(true){
            // Partition array and get pivot's final position
            int pivotIndex = partition(nums, left, right);

            // If pivot is at the target position, we found the kth largest
            if(pivotIndex == target){
                return nums[pivotIndex];
            }
            // If pivot is left of target, search right half
            else if(pivotIndex < target){
                left = pivotIndex + 1;
            }
            // If pivot is right of target, search left half
            else{
                right = pivotIndex - 1;
            }
        }   
    }

private: 
    // Partition function: arranges elements in descending order around pivot
    // Elements >= pivot go to left, elements <= pivot go to right
    int partition(vector<int>& nums, int left, int right){
        int pivot = nums[left];    // Choose leftmost element as pivot
        int i = left + 1;          // Left pointer (start after pivot)
        int j = right;             // Right pointer (start at end)

        while(true){
            // Move i right until we find element < pivot (violates descending order)
            while(i <= j && nums[i] >= pivot) i++;
            
            // Move j left until we find element > pivot (violates descending order)
            while(i <= j && nums[j] <= pivot) j--;

            // If pointers crossed, partitioning is complete
            if(i > j) break;
            
            // Swap elements to maintain descending order
            swap(nums[i], nums[j]);
        }

        // Place pivot in its final sorted position (at index j)
        swap(nums[left], nums[j]);
        return j;  // Return pivot's final index
    }
};