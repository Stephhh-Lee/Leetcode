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
    void getVector(TreeNode* root, vector<int>& vec){
        if(root->right == nullptr && root->left == nullptr) vec.push_back(root->val);
        if(root->left != nullptr) getVector(root->left, vec);
        if(root->right != nullptr) getVector(root->right, vec);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> vec1;
        vector<int> vec2;
        getVector(root1, vec1);
        getVector(root2, vec2);
        if(vec1.size() != vec2.size()) return false;
        while(!vec1.empty()){
            if(vec1.back() != vec2.back()) return false;
            vec1.pop_back();
            vec2.pop_back();
        }
        return true;
    }
};
