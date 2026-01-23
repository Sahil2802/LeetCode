class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // exactly k odds = atMost(k odds) - atMost(k-1 odds)
        return atMost(nums, k) - atMost(nums, k - 1);
    }

    int atMost(vector<int>& nums, int k) {
        int n = nums.size();

        long long count = 0;   // total subarrays with <= k odd numbers
        int oddCount = 0;      // number of odds in current window
        int left = 0;          // left pointer of sliding window
        int right = 0;         // right pointer of sliding window

        while (right < n) {

            // expand window by including nums[right]
            if (nums[right] % 2 == 1) oddCount++;

            // shrink window until it has at most k odd numbers
            while (oddCount > k) {
                if (nums[left] % 2 == 1) oddCount--;
                left++;
            }

            // all subarrays ending at 'right' and starting from [left..right] are valid
            // number of such subarrays = (right - left + 1)
            count += (right - left + 1);

            // move right forward to expand window further
            right++;
        }

        return count;
    }
};
