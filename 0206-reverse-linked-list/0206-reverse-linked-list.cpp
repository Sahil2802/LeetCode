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
    ListNode* reverseList(ListNode* head) {
        // Base case: if the list is empty or has only one node, return the head
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Recursively reverse the rest of the list
        ListNode* newHead = reverseList(head->next);

        // Reverse the current node's pointer
        ListNode* front = head->next; // Get the next node
        front->next = head;           // Make the next node point to the current node
        head->next = nullptr;         // Set the current node's next to nullptr

        // Return the new head of the reversed list
        return newHead;
    }
};