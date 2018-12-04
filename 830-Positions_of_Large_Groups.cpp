class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        int start = 0, end = 0;
        vector<vector<int>> ans;
        vector<int> tmp;
        for(int i = 1; i < S.size(); i++){
            if(S[i] == S[i-1] && i+1 < S.size()) end++;
            else{
                if(i+1 == S.size() && S[i] == S[i-1]) end++;
                if(end - start > 1){
                    tmp.push_back(start);
                    tmp.push_back(end);
                    ans.push_back(tmp);
                    tmp.clear();
                }
                start = end = i;
            }
        }
        return ans;
    }
};
