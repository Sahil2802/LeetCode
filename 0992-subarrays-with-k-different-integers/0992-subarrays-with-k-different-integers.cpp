class Solution {
public:
    // Count subarrays with exactly k distinct = atMost(k) - atMost(k-1)
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

    // Count subarrays with at most k distinct elements using sliding window
    int atMost(vector<int>& nums, int k) {
        unordered_map<int, int> freq; // frequency of each element in current window
        int left = 0;
        int count = 0;

        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;

            // Shrink window from left until we have at most k distinct elements
            while (freq.size() > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]); // remove element once its count drops to zero
                }
                left++;
            }

            // All subarrays ending at `right` with left..right as the window are valid
            count += (right - left + 1);
        }

        return count;
    }
};
