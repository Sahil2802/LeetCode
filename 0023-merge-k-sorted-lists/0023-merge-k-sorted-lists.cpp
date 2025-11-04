/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Custom comparator for min heap
// Returns true if l's value is greater than r's value (for min heap behavior)
struct compare {
    bool operator()(const ListNode* l, const ListNode* r){
        return l->val > r->val;  // Min heap: smaller values have higher priority
    }
};

class Solution {
public:
    // Merge K sorted linked lists into one sorted linked list
    // Time Complexity: O(N log k) where N = total nodes, k = number of lists
    // Space Complexity: O(k) for the priority queue
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min heap to store nodes from all lists
        // Always gives us the smallest node among all list heads
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        
        // Step 1: Initialize heap with the head of each non-empty list
        for(auto node : lists){
            if(node) pq.push(node);  // Only add non-null heads
        }

        // Step 2: Create dummy node to build result list
        ListNode* dummy = new ListNode(0);  // Dummy head for easier list construction
        ListNode* tail = dummy;             // Tail pointer to append nodes

        // Step 3: Extract smallest node repeatedly and add to result
        while(!pq.empty()){
            // Get the node with smallest value from heap
            ListNode* smallest = pq.top();
            pq.pop();
            
            // Append smallest node to result list
            tail->next = smallest;
            tail = tail->next;

            // If this node has a next node, add it to heap
            // This maintains the invariant: heap contains one node from each active list
            if(smallest->next){
                pq.push(smallest->next);
            }
        }
        
        // Return the actual head (skip dummy node)
        return dummy->next;
    }
};