class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="(";
        helper(s,n-1,n,ans);
        return ans;
    }
    void helper(string s, int m, int n, vector<string>& ans) {
        if(n<m) return;
        if(m==0 && n==0){
            ans.push_back(s);
            return;
        }
        else if(m==0) helper(s+')', m, n-1, ans);
        else {
            helper(s+'(', m-1, n, ans);
            helper(s+')', m, n-1, ans);
        }
    }
};
