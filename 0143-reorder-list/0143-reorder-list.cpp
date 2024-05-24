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
        if (!head || !head->next)
            return;

        // Find the middle of the llist
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the llist
        ListNode* newNode = reverseList(slow->next);
        slow->next = NULL;

        // Merge both halves of the list
        ListNode* curr = head;
        ListNode* dummy = newNode;
        while (curr && dummy) {
            ListNode* temp = curr->next;
            curr->next = dummy;
            ListNode* temp2 = dummy->next;
            dummy->next = temp;
            curr = temp;
            dummy = temp2;
        }
        
    }
    
    // Function to reverse a linked list
    ListNode* reverseList(ListNode* node) {
        ListNode* prev = nullptr;
        ListNode* curr = node;
        ListNode* next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
        
};