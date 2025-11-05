class Solution {
public:
    // Calculate the minimum time needed to execute all tasks with cooling interval
    // Time Complexity: O(n log n), Space Complexity: O(26) = O(1) for max 26 task types
    int leastInterval(vector<char>& tasks, int n) {
        // Step 1: Count frequency of each task type
        unordered_map<char, int> freq;
        for(auto task : tasks){
            freq[task]++;
        }
        
        // Step 2: Create max heap with task frequencies
        // Most frequent tasks need to be scheduled first to minimize idle time
        priority_queue<int> pq;
        for(auto [ch, count] : freq){
            pq.push(count);  // Only store counts, not task names
        }

        int time = 0;  // Total time units needed
        
        // Step 3: Process tasks in cycles of (n+1) to respect cooling period
        while(!pq.empty()){
            vector<int> temp;      // Store tasks that still have remaining executions
            int cycle = n + 1;     // Each cycle has (n+1) slots to ensure n gaps between same tasks
            
            // Step 4: Execute tasks within current cycle
            while(cycle > 0 && !pq.empty()){
                int topFreq = pq.top();  // Get most frequent remaining task
                pq.pop();
                
                topFreq--;  // Execute one instance of this task
                
                // If task still has remaining executions, save for later
                if(topFreq > 0) temp.push_back(topFreq);
                
                cycle--;  // One slot used in this cycle
                time++;   // One time unit elapsed
            }
            
            // Step 5: Re-add tasks that still need execution back to heap
            for(auto remTask : temp){
                pq.push(remTask);
            }
            
            // Step 6: If tasks remain, add idle time for remaining slots in cycle
            // This ensures proper cooling period between same task executions
            if(!pq.empty()){
                time += cycle;  // Add remaining idle slots in this cycle
            }
        }
        
        return time;  // Total time including task execution and idle periods
    }
};