/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // if both nodes are NULL  
        if (p == NULL && q == NULL){
            return true;
        }
        // if one of the nodes is NULL
        if (p == NULL || q == NULL){
            return false;
        }
        // check if the values at the nodes are equal and recursively check left and right subtree
        if (p->val == q->val){
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        // Tree is not identical
        return false;
    }
};