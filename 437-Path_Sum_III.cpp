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
    int ans;
    void helper(TreeNode* root, int sum, int target){
        if(root != nullptr)
        {
            int n = root->val;
            if(sum + n == target){
                ans++;
            }
            helper(root->left, sum+n, target);
            helper(root->right, sum+n, target);
            helper(root->left, 0, target);
            helper(root->right, 0, target);
        }
    }
    int pathSum(TreeNode* root, int sum) {
        ans = 0;
        if(root){
            //if(root->right == nullptr && root->left == nullptr && root->val == sum) return 1;
            helper(root, 0, sum);
        }
        return ans;
    }
};

//以上解法不对，但是为什么不对呢？
