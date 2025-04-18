class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans; // Result vector to store merged intervals
        int n = intervals.size(); // Number of intervals

        // Step 1: Sort the intervals based on their starting points
        // If the starting points are equal, sort by the second element (end time)
        sort(intervals.begin(), intervals.end());

        // Step 2: Iterate through the intervals
        for (int i = 0; i < n; i++) {
            // Step 3: Check if the current interval overlaps with the last interval in the result
            if (!ans.empty() && intervals[i][0] <= ans.back()[1]) {
                // If overlapping, merge the intervals by updating the end time
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                // If not overlapping, add the current interval to the result
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};