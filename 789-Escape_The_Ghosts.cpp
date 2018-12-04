class Solution {
public:
    int helper(vector<int> v1, vector<int> v2){
        return abs(v1[0]-v2[0])+abs(v1[1]-v2[1]);
    }
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int len = helper(target, {0, 0});
        for(auto x:ghosts){
            if(helper(x,target) < len) return false;
        }
        return true;
    }
};
