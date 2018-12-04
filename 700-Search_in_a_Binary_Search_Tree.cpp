class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* p = root;
        //TreeNode* q = root;
        while(p){
            //q = p;
            if(p->val > val) p = p->left;
            else if(p->val == val) return p;
            else p = p->right;
        }

        return NULL;
    }
};
