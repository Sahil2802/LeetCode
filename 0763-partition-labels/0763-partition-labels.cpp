class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();

        // lastSeen[c] = last index where character c appears.
        vector<int> lastSeen(26, -1);
        for (int i = 0; i < n; i++) {
            lastSeen[s[i] - 'a'] = i;
        }

        vector<int> result;
        int start = 0;  // start index of current partition
        int end = 0;    // farthest index needed for current partition

        for (int i = 0; i < n; i++) {
            // Extend the partition to include all occurrences of s[i].
            end = max(end, lastSeen[s[i] - 'a']);

            // If we reached the end, finalize this partition.
            if (i == end) {
                result.push_back(end - start + 1);
                start = end + 1;
            }
        }

        return result;
    }
};