class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> tmp;
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j <= i; j++){
                if(j==0 || j==i) tmp.push_back(1);
                else tmp.push_back(ans[i-1][j-1] + ans[i-1][j]);
            }
            ans.push_back(tmp);
            tmp.clear();
        }
        return ans;
    }
};
