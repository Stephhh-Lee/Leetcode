class Solution {
public:
    bool buddyStrings(string A, string B) {
        unordered_map<char,int> m;
        vector<int> diff;
        int diff_tmp = 0;
        bool tmp = false;
        if(A.size() != B.size()) return false;
        for(int i = 0; i < A.size(); ++i){
            if(A[i] != B[i]){
                diff_tmp++;
                if(diff_tmp>2) return false;
                if(diff_tmp == 1){
                    diff.push_back(A[i]);
                    diff.push_back(B[i]);
                }
                if(diff_tmp == 2){
                    if(diff[0] != B[i] || diff[1] != A[i]) return false;
                }
            }
            if(!tmp){
                if((++m[A[i]]) == 2) tmp = true;
            }
        }
        if(!tmp && diff_tmp == 0) return false;
        return true;
    }
};
