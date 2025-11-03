class Solution {
public:
    // Find the Kth largest element using a Min Heap (Priority Queue)
    // Time Complexity: O(n log k), Space Complexity: O(k)
    int findKthLargest(vector<int>& nums, int k) {
        // Create a min heap with size k
        // greater<int> makes it a min heap (smallest element at top)
        priority_queue<int, vector<int>, greater<int>> pq;

        // Iterate through all numbers in the array
        for(int num : nums){
            // Add current number to the min heap
            pq.push(num);

            // If heap size exceeds k, remove the smallest element
            // This ensures we always keep the k largest elements
            if(pq.size() > k){
                pq.pop();
            }
        }

        // The top of the min heap is the kth largest element
        // (smallest among the k largest elements)
        return pq.top();
    }
};