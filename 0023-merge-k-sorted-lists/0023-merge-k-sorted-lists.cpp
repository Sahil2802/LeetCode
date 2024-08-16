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
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        for(int i = 0; i < arr.size(); i++){
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }
        return dummyNode->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector <int> arr;

        for(int i = 0; i < lists.size(); i++){
            ListNode* temp = lists[i];

            while(temp){
                arr.push_back(temp->val);
                temp = temp->next;
            }

        }
        sort(arr.begin(), arr.end());
        return arrayToLL(arr); 
    }
};