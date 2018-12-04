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
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N%2 == 0) return {};
        if(N == 1) return { new TreeNode(0) };
        vector<TreeNode*> ans;
        for(int i = 1; i < N; i++){
            for(TreeNode* &L : allPossibleFBT(i)){
                for(TreeNode* &R : allPossibleFBT(N-i-1)){
                    TreeNode* root = new TreeNode(0);
                    root->left = L;
                    root->right = R;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};
