/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //观摩大佬的代码！！！

class Solution {
    vector<TreeNode*> nodes;
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s && !t) return true;
        if(!s || !t) return false;
        getDepth(s, getDepth(t, -1));

        for(auto x:nodes){
            if(identical(x, t))
                return true;
        }
        return false;
    }
    int getDepth( TreeNode* r, int d){
        if(!r) return -1;

        int depth = max(getDepth(r->left, d), getDepth(r->right, d)) + 1;

        if(depth == d) nodes.push_back(r);

        return depth;
    }

    bool identical(TreeNode* a, TreeNode* b){
        if(!a && !b) return true;
        if(!a || !b || a->val != b->val) return false;

        return identical(a->left, b->left) && identical(a->right, b->right);
    }

};
