class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(); // Get the number of intervals
        int i = 0;
        vector<vector<int>> ans; 

        // Case 1: Add all intervals that come before the newInterval (non-overlapping intervals)
        // These intervals end before the newInterval starts
        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]); // Add the current interval to the result
            i++; // Move to the next interval
        }

        // Case 2: Merge all overlapping intervals with the newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            // Update the start of the newInterval to the minimum start of overlapping intervals
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            // Update the end of the newInterval to the maximum end of overlapping intervals
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++; // Move to the next interval
        }
        // Add the merged newInterval to the result
        ans.push_back(newInterval);

        // Case 3: Add all intervals that come after the newInterval (non-overlapping intervals)
        // These intervals start after the newInterval ends
        while (i < n) {
            ans.push_back(intervals[i]); // Add the current interval to the result
            i++; // Move to the next interval
        }
        return ans;
    }
};