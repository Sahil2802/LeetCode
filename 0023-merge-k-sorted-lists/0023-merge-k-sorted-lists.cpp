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
    ListNode* arrayToLL(vector<int>& arr){
        ListNode* dummyNode = new ListNode(-1); // Create a dummy node
        ListNode* temp = dummyNode; // Temp pointer to build the new linked list

        // Loop through the array and create a linked list node for each element
        for(int i = 0; i < arr.size(); i++){
            // Create a new node with the current array element
            temp->next = new ListNode(arr[i]);
            // Move the temp pointer to the new node
            temp = temp->next;
        }
        // Return the head of the new linked list (skip the dummy node)
        return dummyNode->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector <int> arr; // Vector to store all the values from the given linked lists
        // Loop through each linked list
        for(int i = 0; i < lists.size(); i++){
            // Temp pointer to traverse the current linked list
            ListNode* temp = lists[i];

            // Traverse the current linked list and store its values in the array
            while(temp){
                arr.push_back(temp->val); // Add the value to the array
                temp = temp->next; // Move to the next node
            }

        }
        // Sort the array of values
        sort(arr.begin(), arr.end());
        // Convert the sorted array back to a linked list
        return arrayToLL(arr); 
    }
};