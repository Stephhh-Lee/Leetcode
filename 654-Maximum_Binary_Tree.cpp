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
    TreeNode* helper(vector<int>& nums, int start, int end){
        if(start>end) return nullptr;
        int Max = INT_MIN, mark;
        for(int i = start; i <= end; i++){
            if(nums[i] > Max){
                Max = nums[i];
                mark = i;
            }
        }
        TreeNode* root =new TreeNode(0);
        root->val = Max;
        root->left = helper(nums, start, mark-1);
        root->right = helper(nums, mark+1, end);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* ans;
        ans = helper(nums, 0, nums.size()-1);
        return ans;
    }
};
