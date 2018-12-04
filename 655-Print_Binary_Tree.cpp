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
    void getHeight(TreeNode* root, int& h, int i){
        //i++;
        if(root==nullptr && h<i){
            h=i;
            return;
        }
        if(root==nullptr) return;
        getHeight(root->left, h ,i+1);
        getHeight(root->right, h ,i+1);
    }
    string int2string(int num){
        stringstream ss;
        string s;
        ss<<num;
        ss>>s;
        return s;
    }
    void helper(TreeNode* root, vector<string>& vec, pair<int, int> loc){
        int start=loc.first, end=loc.second;
        int mid = (start+end)/2;
        vec[mid]+=int2string(root->val);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int height=0;
        getHeight(root, height, 0);
        vector<vector<string>> ans;
        queue<TreeNode*> qTree;
        queue<pair<int, int>> qPair;
        qTree.push(root);
        qPair.push(make_pair(0,pow(2,height)-1));

        for(int i=0; i<height; i++){
            vector<string> vec(pow(2,height)-1, "");
            int times = qTree.size();
            for(int j=0; j<times; j++){
                TreeNode* tn=qTree.front();
                pair<int, int> loc=qPair.front();
                helper(tn, vec, loc);
                if(tn->left!=nullptr){
                    qTree.push(tn->left);
                    qPair.push(make_pair(loc.first,(loc.first+loc.second)/2-1));
                }
                if(tn->right!=nullptr){
                    qTree.push(tn->right);
                    qPair.push(make_pair((loc.first+loc.second)/2+1, loc.second));
                }
                qTree.pop();
                qPair.pop();
            }
            ans.push_back(vec);
        }
        return ans;



        //helper(root, ans, 0, ans.size()-1);
    }
};
