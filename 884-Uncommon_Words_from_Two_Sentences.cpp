class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> m;
        vector<string> ans;
        for(int i = 0; i < A.size(); i++){
            string s = "";
            while(A[i] != ' ' && i < A.size()){
                s += A[i];
                i++;
            }
            m[s]++;
        }
        for(int i = 0; i < B.size(); i++){
            string s = "";
            while(B[i] != ' ' && i < B.size()){
                s += B[i];
                i++;
            }
            m[s]++;
        }
        for(auto x:m){
            if(x.second == 1) ans.push_back(x.first);
        }
        return ans;
    }
};
