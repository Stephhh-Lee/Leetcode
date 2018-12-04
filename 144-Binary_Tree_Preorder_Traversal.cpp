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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};
        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        ans.push_back(root->val);
        while(!s.empty()){
            while(s.top()->left != nullptr){
                ans.push_back(s.top()->left->val);
                s.push(s.top()->left);
            }
            while(s.top()->right == nullptr){
                s.pop();
                if(s.empty()) break;
            }
            if(!s.empty()){
                TreeNode* node = s.top()->right;
                s.pop();
                s.push(node);
                ans.push_back(node->val);
            }
        }
        return ans;
    }
};
