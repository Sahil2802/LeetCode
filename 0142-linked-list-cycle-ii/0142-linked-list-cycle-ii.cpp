/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Initialize two pointers, slow and fast, both starting at the head
        ListNode* slow = head;
        ListNode* fast = head;

        // Traverse the list with slow and fast pointers
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;        // Move slow pointer one step
            fast = fast->next->next;  // Move fast pointer two steps

            // If slow and fast pointers meet, there is a cycle
            if (slow == fast) {
                slow = head; // Move slow pointer to the head
                // Move both pointers one step at a time until they meet
                // The meeting point is the start of the cycle
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                // Return the start of the cycle
                return slow;
            }
        }
        // If we reach the end of the list, there is no cycle
        return nullptr;
    }
};