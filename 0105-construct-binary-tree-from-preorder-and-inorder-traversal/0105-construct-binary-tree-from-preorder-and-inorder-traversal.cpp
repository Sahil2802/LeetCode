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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map <int, int> mp;
        for(int i = 0; i < preorder.size(); i++){
            mp[inorder[i]] = i;
        }

        // Initialize the index variable to track the current position in the preorder traversal
        int index = 0;

        return build(preorder, mp, index, 0, inorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder, unordered_map<int, int>& mp, int& index, int i, int j) {
        // Base case: if the start index exceed the end index, i.e. NULL subtree.
        if (i > j){
            return NULL;
        }

        // create a new tree node root and assign it to the value from the preorder traversal at the curr index.
        TreeNode* root = new TreeNode(preorder[index]);
        index++;

        // Find the index of the root value in the inorder traversal store in the map
        int mid = mp[root->val];

        // Recursively build the left subtree with elements to the left of the root in the inorder traversal
        root->left = build(preorder, mp, index, i, mid - 1);
        // Recursively build the left subtree with elements to the right of the root in the inorder traversal
        root->right = build(preorder, mp, index, mid + 1, j);
        return root;
    }
};