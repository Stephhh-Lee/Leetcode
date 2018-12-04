class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        if(root == nullptr) return 0;
        int dep = 0;
        for(auto n : root->children)
            dep = max(dep, maxDepth(n));
        return dep + 1;
    }
};
