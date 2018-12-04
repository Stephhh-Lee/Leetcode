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
    bool helper(TreeNode* root, int sum, int target){
        if(root->left == nullptr && root->right == nullptr)
            if(sum+root->val == target) return true;
            else return false;
        else if(root->left && root->right)
            return helper(root->left, sum+root->val, target) || helper(root->right, sum+root->val, target);
        else if(root->left) return helper(root->left, sum+root->val, target);
        else return helper(root->right, sum+root->val, target);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr) return false;
        return helper(root,0,sum);
    }
};
