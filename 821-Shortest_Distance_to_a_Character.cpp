class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> ans(S.size(), INT_MAX-1);
        //vector<int> backward(s.size(), INT_MAX);
        for(int i = 0; i < S.size(); i++){
            if(S[i] == C) ans[i] = 0;
            else if(i > 0){
                ans[i] = min(ans[i], ans[i-1] + 1);
            }
        }
        for(int i = S.size() - 2; i >= 0; i--){
            ans[i] = min(abs(ans[i]), abs(ans[i+1] + 1));
        }
        return ans;
    }
};
