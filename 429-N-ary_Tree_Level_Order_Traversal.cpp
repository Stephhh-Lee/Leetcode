class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        vector<int> tmp;
        vector<Node*> floor;
        int height = 0;

        if(root != nullptr){
            tmp.push_back(root->val);
            floor.push_back(root);
            while(!tmp.empty()){
                //ans[height].insert(ans.end(), tmp.begin(), tmp.end());
                for(int i=0; i<tmp.size(); i++){
                    if(!(floor[i]->children.empty()))
                        floor.insert(floor.end(), floor[i]->children.begin(), floor[i]->children.end());
                }
                for(int i=0; i<tmp.size(); i++){
                    vector<Node*>::iterator it = floor.begin();
                    floor.erase(it);
                }
              ans.push_back(tmp);
                while(!tmp.empty()) tmp.pop_back();
                for(auto x:floor){
                    tmp.push_back(x->val);
              }
                height++;
            }
        }
        return ans;
    }
};
