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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> q;
        if(!root) return 0;
        int ans = 0;
        q.push(root);
        while(true){
            int size = q.size();
            ans++;
            while(size--){
                TreeNode* p = q.front();
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
                if(!p->left && !p->right) return ans;
                q.pop();
            }
        }
    }
};