class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int mod = 1e9 + 7;

        // Sort the array so that both ends have min and max.
        sort(nums.begin(), nums.end());

        // power[i] = 2^i 
        // This precomputed array helps count how many subsequences can be formed between two pointers.
        vector<int> power(n);
        power[0] = 1;
        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2) % mod;
        }

        int result = 0;
        int left = 0, right = n - 1;

        // Pair the smallest and largest elements.
        while (left <= right) {
            // If nums[left] + nums[right] is valid,
            // then every subset of the elements between them is also valid.
            if (nums[left] + nums[right] <= target) {
                result = (result + power[right - left]) % mod;
                left++;
            } else {
                // Sum is too large, so reduce the larger element.
                right--;
            }
        }

        return result;
    }
};