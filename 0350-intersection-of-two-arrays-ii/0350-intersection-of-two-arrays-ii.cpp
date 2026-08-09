class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> result;

        sort(nums1.begin(), nums1.end()); // needed for two-pointer comparison
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                i++; // nums1's element is smaller, advance it
            }
            else if (nums1[i] > nums2[j]) {
                j++; // nums2's element is smaller, advance it
            }
            else {
                // match found, keep it (no duplicate-skip check needed here,
                // since this version wants every matching occurrence)
                result.push_back(nums1[i]);
                i++; // move both pointers past this matched value
                j++;
            }
        }
        return result;
    }
};