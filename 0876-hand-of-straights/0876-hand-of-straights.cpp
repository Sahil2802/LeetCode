class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        
        // Step 1: Check if total cards can be evenly divided into groups
        // If not divisible, it's impossible to form equal-sized groups
        if(n % groupSize != 0) return false;

        unordered_map<int, int> freq;
        for(int card : hand) freq[card]++;

        priority_queue<int, vector<int>, greater<int>> minHeap(hand.begin(), hand.end());
        while(!minHeap.empty()){
            int start = minHeap.top();
            minHeap.pop();

            if(freq[start] == 0) continue;

            for(int i = 0; i < groupSize; i++){
                int curr = start + i;
                if(freq[curr] == 0) return false;
                freq[curr]--;
            }
        }
        return true;
    }
};