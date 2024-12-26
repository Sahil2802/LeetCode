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
    ListNode* reverseLL(ListNode* head) {
        ListNode* curr = head;
        ListNode* prevNode = nullptr;
        ListNode* nextNode = nullptr;

        // Traverse the list and reverse the pointers
        while (curr != nullptr) {
            nextNode = curr->next;  // Store the next node
            curr->next = prevNode;  // Reverse the current node's pointer
            prevNode = curr;        // Move prevNode to the current node
            curr = nextNode;        // Move curr to the next node
        }
        return prevNode; // Return the new head of the reversed list
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;

        // Find the middle of the list using slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        ListNode* newHead = reverseLL(slow);
        ListNode* first = head;
        ListNode* second = newHead; // Pointer for the first element of the 2nd half of the list

        // Compare the first half and the reversed second half
        while (second != nullptr) {
            if (first->val != second->val) {
                return false;
            }
            first = first->next;
            second = second->next;
        }

        return true;
    }
};