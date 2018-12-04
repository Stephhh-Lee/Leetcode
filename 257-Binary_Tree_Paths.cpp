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
    string int2str(int i){
        stringstream ss;
        string s;
        ss<<i;
        ss>>s;
        return s;
    }
    void getPath(TreeNode* node, string s, vector<string>& ans){
        //char c = node->val+'0';
        s=s+"->"+int2str(node->val);
        if(node->left != nullptr) getPath(node->left, s, ans);
        if(node->right != nullptr) getPath(node->right, s, ans);
        if(node->left == nullptr && node->right == nullptr) ans.push_back(s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s = "";
        if(root != nullptr){
            //char c = int2str(root->val);
            if(root->left) getPath(root->left, s+int2str(root->val), ans);
            if(root->right) getPath(root->right, s+int2str(root->val), ans);
            if(root->left == nullptr && root->right == nullptr) ans.push_back(s+int2str(root->val));
        }
        return ans;
    }
};
