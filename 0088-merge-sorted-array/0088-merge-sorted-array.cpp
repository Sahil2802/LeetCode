class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;      // pointer to last valid element in nums1
        int j = n - 1;      // pointer to last element in nums2
        int k = m + n - 1;  // write pointer, last position of merged array

        // Merge from the back so we never overwrite unprocessed nums1 elements
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                // nums1's current element is bigger, place it at the end
                nums1[k] = nums1[i];
                i--;
            } else {
                // nums2's current element is bigger (or nums1 exhausted)
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        // If nums1 still has elements left (i >= 0), they're already
        // smaller than everything placed so far and sit correctly at the front
    }
};