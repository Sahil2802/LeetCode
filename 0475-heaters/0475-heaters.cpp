class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());   // needed so j only moves forward
        sort(heaters.begin(), heaters.end());

        int maxRadius = 0;
        int j = 0; // pointer into heaters, tracks best heater candidate
        int m = heaters.size();

        for (int house : houses) {
            // Move j forward while the NEXT heater is at least as close
            // as the current one -- keep advancing toward the closest heater
            while (j < m - 1 && abs(heaters[j + 1] - house) <= abs(heaters[j] - house)) {
                j++;
            }

            // heaters[j] is now the closest heater for this house
            // track the worst case across all houses (max of min distances)
            maxRadius = max(maxRadius, abs(heaters[j] - house));
        }

        return maxRadius;
    }
};