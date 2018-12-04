class Solution {
public:
    int caculValue(TreeNode* root, unordered_map<int, int>& m){
        int nodeValue = root->val;
        //if(root->left == nullptr && root->right == nullptr) nodeValue = root->val;
        if(root->left != nullptr) nodeValue += caculValue(root->left, m);
        if(root->right != nullptr) nodeValue += caculValue(root->right, m);
        m[nodeValue]++;
        return nodeValue;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> m;
        vector<int> ans;
        int max = INT_MIN;
        if(root != nullptr)
            caculValue(root, m);
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
