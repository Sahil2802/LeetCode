class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> merged;
        
        // Take valid elements from nums1
        for (int i = 0; i < m; i++) {
            merged.push_back(nums1[i]);
        }
        
        // Take all elements from nums2
        for (int i = 0; i < n; i++) {
            merged.push_back(nums2[i]);
        }
        
        // Sort combined array
        sort(merged.begin(), merged.end());
        
        // Copy back into nums1
        for (int i = 0; i < m + n; i++) {
            nums1[i] = merged[i];
        }
    }
};