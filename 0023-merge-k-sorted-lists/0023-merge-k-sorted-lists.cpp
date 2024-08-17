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
    // Function to merge two sorted linked lists
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* dummyNode = new ListNode(-1); // Create a dummy node
        ListNode* temp = dummyNode; // Pointer to build the merged list

        // Traverse both lists and link nodes in sorted order
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val < list2->val){
                temp->next = list1; // Link the smaller node to the merged list
                list1 = list1->next; // Move to the next node in list1
            }
            else{
                temp->next = list2; // Link the smaller node to the merged list
                list2 = list2->next; // Move to the next node in list2
            }
            temp = temp->next; // Move the pointer in the merged list
        }

        // Append the remaining nodes
        if (list1 != nullptr) {
            temp->next = list1;
        } 
        else {
            temp->next = list2;
        }
        // Return the head of the merged list skipping dummyNode
        return dummyNode->next;
    }

    // Function to recursively divide and merge the lists
    ListNode* mergeSort(vector<ListNode*>& lists, int start, int end){
        // Base case: only one list
        if (start == end) return lists[start];

        // Divide the lists into two halves
        int mid = start + (end - start) / 2;
        
        ListNode* left = mergeSort(lists, start, mid); // Recursively sort the left half
        ListNode* right = mergeSort(lists, mid + 1, end); // Recursively sort the right half
        // Merge the two sorted halves
        return merge(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr; // if the list is empty
        return mergeSort(lists, 0, lists.size() - 1);
    }
};