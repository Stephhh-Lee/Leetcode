class Solution {
public:
    void helper(vector<vector<int>>& graph, int ind, vector<vector<int>>& ans, vector<int> path){
        if(ind == graph.size()-1){
            ans.push_back(path);
            return;
        }
        for(int i = 0; i < graph[ind].size(); i++){
            path.push_back(graph[ind][i]);
            helper(graph, graph[ind][i], ans, path);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        path.push_back(0);
        helper(graph, 0, ans, path);
        return ans;
    }
};
