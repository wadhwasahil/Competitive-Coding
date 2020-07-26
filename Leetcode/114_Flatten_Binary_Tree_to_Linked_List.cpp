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
    TreeNode* solve(TreeNode* root) {
        if(root == NULL) return root;
        TreeNode* left_ptr = NULL;
        TreeNode* right_ptr = NULL;
        if(root->left != NULL) {
            left_ptr = solve(root->left);
        }
        if(left_ptr != NULL) {
            TreeNode* node_right = root->right;
            left_ptr->right = node_right;
            root->right = root->left;
            root->left = NULL;
        }
         if(root->right != NULL) {
            right_ptr = solve(root->right);
        }
        return right_ptr?right_ptr:(left_ptr?left_ptr:root);
    }
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        solve(root);
    }
};
