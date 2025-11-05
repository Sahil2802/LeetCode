class Solution {
public:
    // Check if cards can be divided into groups of consecutive cards
    // Time Complexity: O(n log n), Space Complexity: O(n)
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        
        // Step 1: Check if total cards can be evenly divided into groups
        // If not divisible, it's impossible to form equal-sized groups
        if(n % groupSize != 0) return false;

        // Step 2: Count frequency of each card value
        // Using map (not unordered_map) to maintain sorted order of keys
        // This ensures we process cards from smallest to largest
        map<int, int> freq;
        for(int card : hand) {
            freq[card]++;
        }

        // Step 3: Try to form consecutive groups starting from smallest card
        // Iterate through each unique card value in sorted order
        for(auto [start, count] : freq){
            // If this card value still has remaining cards to be grouped
            if(count > 0){
                // Try to form 'count' number of groups starting from 'start'
                // Each group needs 'groupSize' consecutive cards
                for(int i = 0; i < groupSize; i++){
                    int curr = start + i;  // Next consecutive card needed
                    
                    // Check if we have enough of this consecutive card
                    // We need at least 'count' of each card in the sequence
                    if(freq[curr] < count) return false;
                    
                    // Use 'count' cards of this value for the groups
                    // We have two “1” cards, so we must make two groups that each start at 1:
                    // which means we must remove two cards of each consecutive number.
                    freq[curr] -= count;
                }
            }
        }
        
        // All cards successfully grouped into consecutive sequences
        return true;
    }
};