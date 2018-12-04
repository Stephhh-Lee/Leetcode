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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        const pair<int, TreeNode*> res = dfs(root);
        return res.second;
    }
private:
    pair<int, TreeNode*> dfs(TreeNode* root)
    {
        if (!root) return {0, NULL};
        const pair<int, TreeNode*> left = dfs(root->left);
        const pair<int, TreeNode*> right = dfs(root->right);
        if (left.first == right.first) return {left.first + 1, root};
        if (left.first < right.first) return {right.first + 1, right.second};
        return {left.first + 1, left.second};
    }
};
