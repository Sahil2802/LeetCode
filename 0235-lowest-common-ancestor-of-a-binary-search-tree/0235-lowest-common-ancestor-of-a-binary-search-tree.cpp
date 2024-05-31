/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != NULL){
            // if p and q are smaller than the root
            if (p->val < root->val && q->val < root->val){
                root = root->left;
            }
            // if q and q are greater than the root 
            else if (p->val > root->val && q->val > root->val){
                root = root->right;
            }
            // if one node is on the right and the other is on the left
            else{
                return root;
            }
        }
        return NULL;
    }
};