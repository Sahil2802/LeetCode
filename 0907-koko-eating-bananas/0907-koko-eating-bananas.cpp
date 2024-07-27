class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1; // Minimum possible eating speed
        int r = 1; // Maximum possible eating speed
        // find the maximum number of bananas in a single pile
        for(int pile: piles){
            r = max(pile, r);
        }

        while(l < r){
            int mid = l + (r - l)/2;
            int time = 0;
            // Time taken to eat all bananas at the current eating speed 
            for(int pile: piles){
                time += ceil(pile * 1.0/mid); // Use ceiling to account for partial hours
            }

            // If the total time is within the allowed hours, adjust the upper bound
            if(time <= h){
                r = mid; // reduce the eating speed
            }
            // Increase the lower bound since the current speed is too slow
            else{
                l = mid + 1;
            }
        }
        // The minimum possible eating speed
        return l;
        
    }
};