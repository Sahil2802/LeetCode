class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        long long sum = 0;  // Current window sum
        int count = 0;      // Count of valid subarrays
        
        // Sliding window: expand window by adding arr[i]
        for(int i = 0; i < n; i++){
            // Add current element to the window
            sum += arr[i];

            // Once window reaches size k (i >= k-1 means we have k elements)
            if(i >= k - 1){
                // Check if average meets threshold
                // sum/k >= threshold is equivalent to sum >= threshold*k
                if(sum / k >= threshold){
                    count++;
                }
                
                // Slide the window: remove the leftmost element
                // Window indices: [i-(k-1), i]
                // len(k) = r(i) - left
                // left = r(i) - len(k)
                sum -= arr[i - (k - 1)];
            }
        }
        
        return count; 
    }
};