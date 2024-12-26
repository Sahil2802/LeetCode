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
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // If the list is empty or has only one node, return nullptr
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        // Initialize two pointers, slow and fast, both starting at the head
        ListNode* slow = head;
        ListNode* fast = head;
       
        fast = fast->next->next; // Move the fast pointer two steps ahead initially

        // Traverse the list with slow and fast pointers
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;        // Move slow pointer one step
            fast = fast->next->next;  // Move fast pointer two steps
        }

        // Delete the middle node
        ListNode* delNode = slow->next; // Store the middle node to be deleted
        slow->next = slow->next->next;  // Update the next pointer to skip the middle node
        delete delNode;                 // Free the memory of the deleted node

       
        return head; // Return the modified list
    }
};