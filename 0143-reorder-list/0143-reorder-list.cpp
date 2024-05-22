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
    void reorderList(ListNode* head) {
        // Recursive Approach
        // return if head  contains 0, 1, 2 nodes
        if (!head || !head->next || !head->next->next){
            return;
        }

        // Find the secondLast node
        ListNode* secondLast = head;
        while (secondLast->next->next){
            secondLast = secondLast->next;
        }

        secondLast->next->next = head->next;
        head->next = secondLast->next;

        secondLast->next = NULL;

        reorderList(head->next->next);
    }
};