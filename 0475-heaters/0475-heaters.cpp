class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int maxRadius = 0;

        // For each house, find its closest heater
        for (int house : houses) {
            int minDist = INT_MAX;

            // Check every heater to find the minimum distance to this house
            for (int heater : heaters) {
                minDist = min(minDist, abs(house - heater));
            }

            // Track the worst case (largest minDist) across all houses,
            // since the radius must cover every house simultaneously
            maxRadius = max(maxRadius, minDist);
        }

        return maxRadius;
    }
};