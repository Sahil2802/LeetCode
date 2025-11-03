// Kth Largest Element in a Stream
// Time Complexity: Constructor O(n log k), add() O(log k)
// Space Complexity: O(k)

class KthLargest {
public:
    // Min heap to maintain k largest elements
    // The top of the heap will always be the kth largest element
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;  // Store the value of k
    
    // Constructor: Initialize the data structure with k and initial stream of numbers
    KthLargest(int k, vector<int>& nums) {
        K = k;
        
        // Process each number in the initial stream
        for(int num : nums){
            pq.push(num);  // Add number to min heap

            // If heap size exceeds k, remove the smallest element
            // This maintains only the k largest elements
            if(pq.size() > k){
                pq.pop();
            }
        }
    }
    
    // Add a new value to the stream and return the kth largest element
    int add(int val) {
        pq.push(val);  // Add new value to the min heap
        
        // If heap size exceeds k, remove the smallest element
        // Ensures we always keep only k largest elements
        if(pq.size() > K){
            pq.pop();
        }
        
        // The top of the min heap is the kth largest element
        // (smallest among the k largest elements)
        return pq.top();
    }
};

/**
 * Usage Example:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 * 
 * Algorithm Explanation:
 * - Min heap maintains exactly k largest elements from the stream
 * - Top of heap = smallest of k largest = kth largest overall
 * - When new element added: push to heap, then pop smallest if size > k
 * - This ensures O(log k) time for each add operation
 */