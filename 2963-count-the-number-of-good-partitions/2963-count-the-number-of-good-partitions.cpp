class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9 + 7;

        // Record the last index where each value appears.
        unordered_map<int, int> lastSeen;
        for (int i = 0; i < n; i++) {
            lastSeen[nums[i]] = i;
        }

        // Count how many disjoint segments we can split into.
        int segments = 0;
        int maxLast = 0;

        for (int i = 0; i < n; i++) {
            // Extend the current segment to cover all values seen so far.
            maxLast = max(maxLast, lastSeen[nums[i]]);

            // When we reach the farthest required index, a segment ends.
            if (i == maxLast) {
                segments++;
            }
        }

        long long result = 1;
        for (int i = 0; i < segments - 1; i++) {
            // Each boundary between segments can be cut or not -> 2^(segments-1).
            result = (result * 2) % mod;
        }

        return result;
    }
};