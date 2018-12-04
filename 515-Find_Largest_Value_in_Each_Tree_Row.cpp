class Solution {
public:
    void getValue(vector<int>& v, int height,TreeNode* root) {
        if(root != nullptr){
            height++;   //1, 2, 3, 4
            if(v.size() < height) v.push_back(root->val);
            else v[height - 1] = max(v[height - 1], root->val);
            getValue(v, height, root->left);
            getValue(v, height, root->right);
        }
    }

    vector<int> largestValues(TreeNode* root) {
        int height = 0;
        vector<int> v;
        if(root != nullptr)
            getValue(v, height, root);
        return v;
    }
};
