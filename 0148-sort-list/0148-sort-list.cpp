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
    // Function to find the middle of the linked list
    ListNode* findMiddle(ListNode* head) {
        // Initialize slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head->next; // Start fast one step ahead to get the first middle in case of even length

        // Base case: if the list is empty or has only one node, return the head
        if (head == nullptr || head->next == nullptr) return head;
        
        // Move the fast pointer twice as fast as the slow pointer
        // When the fast pointer reaches the end, the slow pointer will be at the middle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; // Return the middle node
    }

    // Function to merge two sorted linked lists
    ListNode* mergeSort(ListNode* list1, ListNode* list2) {
        // Create a dummy node to serve as the head of the merged list
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        // Traverse both lists simultaneously
        while (list1 != nullptr && list2 != nullptr) {
            // Compare elements of both lists and link the smaller node to the merged list
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next; // Move the temporary pointer to the next node
        }

        // If any list still has remaining elements, append them to the merged list
        if (list1 != nullptr) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }
        // Return the merged list starting from the next of the dummy node
        return dummy->next;
    }

    // Function to sort the linked list using merge sort
    ListNode* sortList(ListNode* head) {
        // Base case: if the list is empty or has only one node, return the head
        if (head == nullptr || head->next == nullptr) return head;

        // Find the middle of the list
        ListNode* middle = findMiddle(head);

        // Split the list into two halves
        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = nullptr; // Split the list

        // Recursively sort each half
        left = sortList(left);
        right = sortList(right);

        // Merge the two sorted halves
        return mergeSort(left, right);
    }
};