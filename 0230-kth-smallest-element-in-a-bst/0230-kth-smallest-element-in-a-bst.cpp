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
    void solve(TreeNode* root, int &count, int &ans, int k){
        if (root == NULL){
            return;
        }

        // traverse the left subtree 
        solve(root->left, count, ans, k);
        // increment the count when function returns
        count++;
        // check if count is equal to the kth smallest element
        if (count == k){
            ans = root->val;
            return;
        }
        // traverse the right subtree if kth smallest element is not found yet 
        solve(root->right, count, ans, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans;
        solve(root, count, ans, k);
        return ans;
    }
};