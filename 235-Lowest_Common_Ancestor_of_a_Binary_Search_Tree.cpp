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
    void setFalse(TreeNode* root, unordered_map<int, bool>& incp, unordered_map<int, bool>& incq){
        if(root != nullptr){
            incp[root->val] = false;
            incq[root->val] = false;
            setFalse(root->left, incp, incq);
            setFalse(root->right, incp, incq);
        }
    }
    void helperP(TreeNode* root, unordered_map<int, bool>& incp, int p){
        if(root->val > p) helperP(root->left, incp, p);
        if(root->val < p) helperP(root->right, incp, p);
        incp[root->val] = true;
        return;
    }
    void helperQ(TreeNode* root, unordered_map<int, bool>& incq, int q){
        if(root->val > q) helperP(root->left, incq, q);
        if(root->val < q) helperP(root->right, incq, q);
        incq[root->val] = true;
        return;
    }
    TreeNode* helper(TreeNode* root, unordered_map<int, bool> incp, unordered_map<int, bool> incq){
        if(root->left != nullptr && incp[root->left->val] && incq[root->left->val])
            return helper(root->left, incp, incq);
        if(root->right != nullptr && incp[root->right->val] && incq[root->right->val])
            return helper(root->right, incp, incq);
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<int, bool> incp;
        unordered_map<int, bool> incq;
        setFalse(root, incp, incq);
        helperP(root, incp, p->val);
        helperQ(root, incq, q->val);
        TreeNode* ans;
        ans = helper(root, incp, incq);
        return ans;
    }
};
