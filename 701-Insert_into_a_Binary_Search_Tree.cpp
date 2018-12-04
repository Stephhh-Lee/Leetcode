class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* p = root;
        TreeNode* q = root;
        while(p){
            q = p;
            if(p->val > val) p = p->left;
            else p = p->right;
        }
        TreeNode* n = new TreeNode(val);
        if(q->val > val) q->left = n;
        else q->right = n;

        return root;
    }
};
