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
    vector<int> inorderTraversal(TreeNode* root) {
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
            if(ptr->left == NULL) v.push_back(ptr->val);
            if(ptr->left != NULL){
                Q.push(ptr);
                Q.push(ptr->left);
                ptr->left = NULL;
            }
            else {
                if(ptr->right != NULL) Q.push(ptr->right);
            }
        }
        return v;
    }
};
