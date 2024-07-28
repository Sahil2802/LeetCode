/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // If the original list is empty, return NULL
        if(!head) return NULL;

        // Pointer to traverse the original list
        Node* curr = head;
        Node* temp = NULL;

        // First pass: copy the nodes and insert them after each original node
        while(curr) {
            // Create a new node with the same value as the current node
            temp = new Node(curr->val);
            // Insert the new node after the current node
            temp->next = curr->next;
            curr->next = temp;
            // Move to the next original node
            curr = temp->next;
        }

        // Reset the pointer to the head of the original list
        curr = head;

        // Second pass: Assign the random pointers for the new nodes
        while(curr) {
            // If the current node's random pointer is NULL, set the new node's random to NULL
            if(curr->random == NULL) {
                curr->next->random = NULL;
            } else {
                // Otherwise, set the new node's random
                curr->next->random = curr->random->next;
            }
            // Move to the next original node, skipping the newly inserted node
            curr = curr->next->next;
        }

        // Third pass: Separate the copied list from the original list
        Node* newHead = head->next; // Pointer to the head of the new list
        Node* newCurr = newHead; // Pointer to traverse the new list
        curr = head; // Reset the pointer to the head of the original list

        while(curr && curr->next) {
            // Restore the next pointer of the original node
            if(curr->next == NULL) {
                curr->next = NULL;
            } else {
                curr->next = curr->next->next;
            }

            // Restore the next pointer of the new node
            if(newCurr->next == NULL) {
                newCurr->next = NULL;
            } else {
                newCurr->next = newCurr->next->next;
            }

            // Move to the next node in both original and new lists
            curr = curr->next;
            newCurr = newCurr->next;
        }

        // Return the head of the newly created list
        return newHead;
    }
};
