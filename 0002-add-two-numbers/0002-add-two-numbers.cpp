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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(-1); // dummy node for the head of the res
        ListNode* curr = dummyHead; // pointer to traverse the result LL
        int carry = 0;
        int sum = 0;
        
        // Traverse both lists until both are exhausted
        while(l1 != NULL || l2 != NULL){
            int sum = carry;

            // Add value from l1 if l1 is not null
            if (l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }

            // Add value from l2 if l2 is not null
            if (l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10; // get the carry
            sum  = sum % 10; // get the ones digit
            curr->next = new ListNode(sum); // create a new node with sum as the value
            curr = curr->next; // move to the next node
        }
        // If there's a remaining carry, add a new node for it
        if (carry){
            curr->next = new ListNode(carry);
        }
        // Return the next node of dummy head which is the head of the result LL
        return dummyHead->next;
    }
};