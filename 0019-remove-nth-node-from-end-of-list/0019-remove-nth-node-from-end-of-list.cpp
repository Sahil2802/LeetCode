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
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // take n steps
        for(int i = 0; i < n; i++){
            fast = fast->next;
        }

        // moce fast and slow by 1 step till fast reaches last element
        while (fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        } 
        
        // remove the elemetn next to slow
        slow->next = slow->next->next;

        return dummy->next;
    }
};