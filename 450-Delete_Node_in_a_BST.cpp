/*
1. ���Ҫɾ���Ľڵ�������, �����ֱ���������滻��λ��, ���������ӵ����������ӵ�Ҫɾ���ڵ���Һ��ӵ������

2. ���Ҫɾ���Ľڵ����Һ���, ��������Һ����滻��λ��, �������Һ��ӵ����������ӵ�Ҫɾ���ڵ�����ӵ����Ҷ�

3. ���Ҫɾ���Ľڵ�������, �����ȡ���ӵ����ҽڵ��滻Ҫɾ���Ľڵ�

4. ���Ҫɾ���Ľڵ����Һ���, �����ȥ�Һ��ӵ�����ڵ��滻Ҫɾ���Ľڵ�.
*/

//Ϊʲô����д�Ĵ���Ϳ���һ���û�У�������

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
