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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        DFS(root, maxSum);
        return maxSum;
        }
    
    int DFS(TreeNode* root, int& maxSum){
        if(root == NULL){
            return 0;
        }

        // Recursively calculate the maxSum of left and right subtrees
        // consider 0 for the negative values
        int lSum = max(0, DFS(root->left, maxSum));
        int rSum = max(0, DFS(root->right, maxSum));

        // update the maximum path sum path sum that includes the current node and both left and right subtrees.
        int currentPathSum = root->val + lSum + rSum;
        // if the current path sum is greater update the overall maximum path sum 
        maxSum = max(maxSum, currentPathSum);

        // Return the maximum path sum that includes the current node and one of its subtrees
        return root->val + max(lSum, rSum);
    }
};