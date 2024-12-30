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
    // Function to find the intersection node of two singly linked lists.
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Initialize two pointers to traverse both lists
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        // Traverse both lists until the pointers meet
        while (tempA != tempB) {
            // If tempA reaches the end of list A, redirect it to the head of list B
            // Otherwise, move to the next node in list A
            tempA = (tempA == nullptr) ? headB : tempA->next;

            // If tempB reaches the end of list B, redirect it to the head of list A
            // Otherwise, move to the next node in list B
            tempB = (tempB == nullptr) ? headA : tempB->next;
        }

        // Return the intersection node (or nullptr if no intersection)
        return tempA;
    }
};