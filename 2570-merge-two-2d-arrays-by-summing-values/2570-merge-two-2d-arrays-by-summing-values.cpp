class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int i = 0, j = 0;
        int m = nums1.size();
        int n = nums2.size();

        vector<vector<int>> result;

        // Two-pointer merge while both arrays have elements
        while (i < m && j < n) {
            int id1 = nums1[i][0];
            int id2 = nums2[j][0];

            if (id1 == id2) {
                // Same id found in both arrays, sum the values
                int sum = nums1[i][1] + nums2[j][1];
                result.push_back({id1, sum});
                i++;
                j++;
            } else if (id1 < id2) {
                // id1 is smaller, add nums1[i] with its value from nums1 only
                result.push_back(nums1[i]);
                i++;
            } else {
                // id2 is smaller, add nums2[j] with its value from nums2 only
                result.push_back(nums2[j]);
                j++;
            }
        }
        
        // nums2 is exhausted, append any remaining entries from nums1
        while (i < m) {
            result.push_back(nums1[i]);
            i++;
        }

        // nums1 is exhausted, append any remaining entries from nums2
        while (j < n) {
            result.push_back(nums2[j]);
            j++;
        }

        return result;
    }
};