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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        if(root == nullptr) return {};
        s.push(root);
        while(!s.empty()){
            while(!s.empty() && s.top()->left!=nullptr){
                s.push(s.top()->left);
            }
            while(!s.empty() && s.top()->right == nullptr){
                ans.push_back(s.top()->val);
                //TreeNode* tn = s.top();
                s.pop();
            }
            if(!s.empty()){
                TreeNode* tn = s.top();
                ans.push_back(s.top()->val);
                s.pop();
                s.push(tn->right);
            }
        }
        return ans;
    }
};
