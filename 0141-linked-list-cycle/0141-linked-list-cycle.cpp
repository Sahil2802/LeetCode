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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr){
            // move slow by one step and fast by 2 steps
            slow = slow->next;
            fast = fast->next->next;

            // check if slow and fast pointers meet
            if (slow == fast){
                // loop detected if true
                return true;
            }
        }
        return false;
    }
};