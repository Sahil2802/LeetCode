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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL){
            return ans;
        }
        queue <TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            int n = q.size();
            vector <int> lvl; // new vector is created for each level of the tree.

            for (int i=0; i<n; i++){
                TreeNode* node = q.front(); // store the front of the queue in the node.
                q.pop();

                // if the curr node is not null add the children of the current node to the queue
                if (node->left != NULL){
                    q.push(node->left);
                }
                if (node->right != NULL){
                    q.push(node->right);
                }

                lvl.push_back(node->val);
            }
            ans.push_back(lvl);
        }
        return ans;
    }
};