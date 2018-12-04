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
    TreeNode* buildTree(vector<int>& nums, int start, int end){
        if(start>end) return nullptr;
        TreeNode* root = new TreeNode(nums[(start+end)/2]);
        root->left = buildTree(nums, start, (start+end)/2 - 1);
        root->right = buildTree(nums, (start+end)/2 + 1, end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root;
        root = buildTree(nums, 0, nums.size()-1);
        return root;
    }
};
