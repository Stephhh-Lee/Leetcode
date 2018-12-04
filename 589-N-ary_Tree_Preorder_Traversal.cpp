class Solution {
public:
    void preOrderTraverse(vector<int>& ans, Node* root){
        if(!root) return;
        ans.push_back(root->val);
        for(auto n:root->children)
            preOrderTraverse(ans, n);
        //preOrderTraverse();
    }
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if(!root) return ans;
        preOrderTraverse(ans, root);
        return ans;
    }
};
