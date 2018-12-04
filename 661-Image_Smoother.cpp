class Solution {
public:
    bool isLegal(int i, int j, int il, int jl){
        if(i>=0 && i< il && j >=0 && j < jl) return true;
        else return false;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> ans(M.size(), vector<int>(M[0].size(), 0));
        for(int i = 0; i < M.size(); i++){
            for(int j = 0; j < M[0].size(); j++){
                int sum = M[i][j], counter = 1;
                if(isLegal(i-1,j-1,M.size(),M[0].size())){sum+=M[i-1][j-1]; counter++;}
                if(isLegal(i-1,j,M.size(),M[0].size())){sum+=M[i-1][j]; counter++;}
                if(isLegal(i-1,j+1,M.size(),M[0].size())){sum+=M[i-1][j+1]; counter++;}
                if(isLegal(i,j-1,M.size(),M[0].size())){sum+=M[i][j-1]; counter++;}
                if(isLegal(i,j+1,M.size(),M[0].size())){sum+=M[i][j+1]; counter++;}
                if(isLegal(i+1,j-1,M.size(),M[0].size())){sum+=M[i+1][j-1]; counter++;}
                if(isLegal(i+1,j,M.size(),M[0].size())){sum+=M[i+1][j]; counter++;}
                if(isLegal(i+1,j+1,M.size(),M[0].size())){sum+=M[i+1][j+1]; counter++;}
                ans[i][j] = sum/counter;
            }
        }
        return ans;
    }
};
