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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> Q;
        vector<int> v;
        if(root == NULL) return v;
        Q.push(root);
        while(!Q.empty()) {
            TreeNode *ptr = Q.top();
            Q.pop();
            if(ptr == NULL) {
                continue;
            }
            if(ptr->right != NULL) Q.push(ptr->right);
            if(ptr->left != NULL){
                Q.push(ptr->left);
            }
            v.push_back(ptr->val);
        }
        return v;
    }
};
