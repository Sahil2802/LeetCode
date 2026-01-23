class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // We need to pick k cards from either end to maximize score
        // Strategy: Use two-pointer approach - start with k cards from left,
        // then gradually replace left cards with right cards
        
        int n = cardPoints.size();
        int lsum = 0, rsum = 0;  // Sum of cards taken from left and right
        int maxSum = 0;  // Maximum score achievable
        
        // Step 1: Take first k cards from left side
        for(int i = 0; i < k; i++){
            lsum += cardPoints[i];
        }
        
        // Initialize maxSum with all k cards from left
        maxSum = lsum;
        
        // Step 2: Replace left cards with right cards one by one
        int rightIndex = n - 1;  // Start from rightmost card
        for(int i = k - 1; i >= 0; i--){
            // Remove one card from left sum
            lsum -= cardPoints[i];
            
            // Add one card from right sum
            rsum += cardPoints[rightIndex];
            rightIndex--;
            
            // Update maximum score with current configuration
            maxSum = max(maxSum, lsum + rsum);
        }
        
        return maxSum;
    }
};