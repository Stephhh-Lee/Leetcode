/*
1. 如果要删除的节点有左孩子, 则可以直接让左孩子替换其位置, 并且让左孩子的右子树连接到要删除节点的右孩子的最左端

2. 如果要删除的节点有右孩子, 则可以让右孩子替换其位置, 并且让右孩子的左子树连接到要删除节点的左孩子的最右端

3. 如果要删除的节点有左孩子, 则可以取左孩子的最右节点替换要删除的节点

4. 如果要删除的节点有右孩子, 则可以去右孩子的最左节点替换要删除的节点.
*/

//为什么别人写的代码就可以一点错都没有？好气啊

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val > key){
            root->left = deleteNode(root->left, key);
            return root;
        }
        else if(root->val < key){
            root->right = deleteNode(root->right, key);
            return root;
        }
        TreeNode* left = root->left, *right = root->right, *tem = left;
        delete root;
        if(!left || !right) return left?left: right;
        while(tem->right) tem = tem->right;
        tem->right = right->left, right->left = left;
        return right;
    }
};
