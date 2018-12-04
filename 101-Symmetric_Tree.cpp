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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return helper(root->left, root->right);
    }
    bool helper(TreeNode* node1, TreeNode* node2){
        if(node1 == nullptr && node2 == nullptr) return true;
        else if(node1 == nullptr || node2 == nullptr) return false;
        else if(node1->val != node2->val) return false;
        else return helper(node1->right, node2-> left) && helper(node1->left, node2->right);
    }
};
