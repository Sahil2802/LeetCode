class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // Sort people by weight so we can pair the lightest and heaviest efficiently.
        sort(people.begin(), people.end());

        int n = people.size();
        int l = 0, r = n - 1;
        int boats = 0;

        // Keep placing people into boats until all are assigned.
        while (l <= r) {
            // Try to pair the lightest and heaviest person.
            // If their combined weight fits, move the left pointer too.
            if (people[l] + people[r] <= limit) {
                l++;
            }

            // The heaviest person always takes a boat, so move right pointer.
            r--;

            // One boat is used in every iteration.
            boats++;
        }

        return boats;
    }
};