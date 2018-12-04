
class Solution {
public:
    void dfs(vector<vector<int>>& M, vector<int>& visited, int line, int tag){
        for(int i=0; i<line; i++){
            if(line!=i && M[line][i]==1 && visited[i]==-1){
                visited[i]=tag;
                dfs(M,visited,i,tag);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        int ans=M.size();
        vector<int> visited(M.size(), -1);
        //visited[0] = 0;
        //dfs(M,visited,0,0);
        int tag = 0;
        for(int i=0; i<visited.size(); i++){
            if(visited[i]==-1){
                visited[i]=tag;
                dfs(M,visited,i,tag);
                tag++;
            }
        }
        return tag;
    }
};
