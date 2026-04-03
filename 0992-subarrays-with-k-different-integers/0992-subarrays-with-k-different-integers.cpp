class Solution {
public:
    // Count subarrays with exactly k distinct numbers.
    // exactly(k) = atMost(k) - atMost(k - 1)
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

private:
    // Sliding window: count subarrays with at most k distinct numbers.
    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0; // No valid subarray if k is negative.

        int left = 0;
        int count = 0;
        unordered_map<int, int> freq; // Stores frequency of elements in window.

        for (int right = 0; right < (int)nums.size(); right++) {
            // Expand window by including nums[right].
            freq[nums[right]]++;

            // Shrink window until it has at most k distinct elements.
            while ((int)freq.size() > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]); // Remove element when frequency hits zero.
                }
                left++;
            }

            // All subarrays ending at right and starting from [left..right] are valid.
            count += (right - left + 1);
        }

        return count;
    }
};