class Solution {
public:
    vector<int> postorder(Node* root) {
        if(root != nullptr)
        {
            for(auto n : root->children)
                postorder(n);
            res.push_back(root->val);
        }
        return res;
    }
private:
    vector<int> res;
};

//stack µÄÊ¹ÓÃ

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if(root){
            stack<Node*> s;
            s.push(root);
            while(!s.empty()){
                Node* node = s.top();
                s.pop();
                ans.push_back(node->val);
                for(auto x:node->children){
                    s.push(x);
                }
            }
            reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};
