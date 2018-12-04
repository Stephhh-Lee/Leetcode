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
    int helper(TreeNode* root){
        if(root == nullptr) return 0;
        int l,r;
        l = helper(root->left);
        r = helper(root->right);
        if(l == 0) root->left = nullptr;
        if(r == 0) root->right = nullptr;
        return l+r+root->val;
    }
    TreeNode* pruneTree(TreeNode* root) {
        helper(root);
        return root;
    }
};
