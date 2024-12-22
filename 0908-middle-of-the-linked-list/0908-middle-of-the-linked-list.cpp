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
    ListNode* middleNode(ListNode* head) {
        // Initialize slow and fast pointers to the head of the list
        ListNode* slow = head;
        ListNode* fast = head;

        // Traverse the list with slow and fast pointers
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;        // Move slow pointer one step
            fast = fast->next->next;  // Move fast pointer two steps
        }

        // When the fast pointer reaches the end of the list,
        // the slow pointer will be at the middle node
        return slow;
    }
};