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
    int preStart;
    TreeNode* helper(vector<int>& pre, vector<int>& post, int postStart, int postEnd){
        if(postStart > postEnd){
            return nullptr;
        }
        int rootVal = post[postEnd];
        TreeNode* root = new TreeNode(rootVal);
        preStart ++;
        if(preStart == pre.size() || postStart == postEnd){
            return root;
        }

        int leftVal = pre[preStart];
        int lri = postStart;
        for(;lri<=postEnd; lri++){
            if(post[lri] == leftVal){
                break;
            }
        }
        root->left = helper(pre, post, postStart, lri);
        root->right = helper(pre, post, lri + 1, postEnd - 1);
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        preStart = 0;
        int n = pre.size();
        return helper(pre, post, 0, n-1);
    }
};
