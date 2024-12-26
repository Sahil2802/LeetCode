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
    ListNode* oddEvenList(ListNode* head) {
        // If the list is empty or has only one node, return the head
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Initialize pointers for odd and even lists
        ListNode* odd = head;           // Pointer to the first odd node
        ListNode* even = head->next;    // Pointer to the first even node
        ListNode* evenHead = even;      // Store the head of the even list to connect later

        // Traverse the list and separate nodes into odd and even lists
        while (even != nullptr && even->next != nullptr) {
            odd->next = odd->next->next; // Link odd nodes
            even->next = even->next->next; // Link even nodes

            odd = odd->next;   // Move odd pointer to the next odd node
            even = even->next; // Move even pointer to the next even node
        }
        odd->next = evenHead; // Connect the end of the odd list to the head of the even list
        return head; // Return the reordered list
    }
};