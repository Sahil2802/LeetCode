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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Initialize the fast pointer to the head of the list
        ListNode* fast = head;

        // Move the fast pointer n nodes ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // If fast becomes nullptr, it means we need to remove the head node
        if (fast == nullptr) {
            ListNode* newHead = head->next; // Store the new head node
            delete head; // Delete the current head node
            return newHead; // Return the new head node
        }

        // Initialize the slow pointer to the head of the list
        ListNode* slow = head;

        // Move both pointers until fast reaches the end of the list
        while (fast->next != nullptr) {
            slow = slow->next; // Move slow pointer one step
            fast = fast->next; // Move fast pointer one step
        }

        // Delete the nth node from the end
        ListNode* delNode = slow->next; // Store the node to be deleted
        slow->next = slow->next->next; // Update the next pointer to skip the node to be deleted
        delete delNode; // Free the memory of the deleted node

        return head; // Return the modified list
    }
};