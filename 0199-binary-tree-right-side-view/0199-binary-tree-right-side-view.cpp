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
    vector<int> rightSideView(TreeNode* root) {
        vector <int> ans; // Vector to store the right side view nodes
        helper(root, 0, ans); // helper function to traverse the tree
        return ans;
    }

private:
    // Helper function for the recursive traversal of the tree.
    void helper(TreeNode* root, int level, vector <int> &ans){
        // If the current node is null, return.
        if (!root) return;

        // If we are visiting this level for the first time, add the node's value to the answer vector.
        if (ans.size() == level){
            ans.push_back(root->val);
        }
        
        // Recursively visit the right subtree first to prioritize right-side nodes.
        helper(root->right, level + 1, ans);
        // Recursively visit the left subtree.
        helper(root->left, level + 1, ans);
    }
};