class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // needed for duplicate skipping + two pointers

        for (int i = 0; i < n - 3; i++) {
            // Skip duplicate values for first element (but always try i=0)
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++) {
                // Skip duplicate values for second element (but always try j=i+1)
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1, right = n - 1; // two pointers on remaining range

                while (left < right) {
                    // Use long long to avoid overflow (nums[i] up to 1e9, sum of 4 can overflow int)
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // Skip duplicates for third element (moving left forward)
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        // Skip duplicates for fourth element (moving right backward)
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++;  // move past the last used left
                        right--; // move past the last used right
                    }
                    else if (sum < target) {
                        left++;  // sum too small, increase it
                    }
                    else {
                        right--; // sum too big, decrease it
                    }
                }
            }
        }
        return result;
    }
};