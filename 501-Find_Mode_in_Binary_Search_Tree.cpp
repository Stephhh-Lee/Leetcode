class Solution {
public:
    void caculCounter(TreeNode* root, unordered_map<int, int>& m){
        int nodeValue = root->val;
        //if(root->left == nullptr && root->right == nullptr) nodeValue = root->val;
        if(root->left != nullptr) caculCounter(root->left, m);
        if(root->right != nullptr) caculCounter(root->right, m);
        m[nodeValue]++;
        //return nodeValue;
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> m;
        vector<int> ans;
        int max = INT_MIN;
        if(root != nullptr)
            caculCounter(root, m);
        for(auto x:m){
            if(max < x.second){
                max = x.second;
                ans.clear();
                ans.push_back(x.first);
            }
            else if(max == x.second) ans.push_back(x.first);
        }
        return ans;
    }
};
