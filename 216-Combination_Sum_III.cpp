class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<bool> selected, vector<int> vec, int k, int n, int index){
        if(k<=0 || n<0) return;
        if(k==1 && n<selected.size() && selected[n]==false && index<n){
            vec.push_back(n);
            ans.push_back(vec);
            return;
        }
        if(n<index) return;
        for(int i=index+1; i<10; i++){
            selected[i]=true;
            vec.push_back(i);
            helper(ans, selected, vec, k-1, n-i, i);
            selected[i]=false;
            vec.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<bool> selected(10, false);
        vector<int> vec;
        helper(ans, selected, vec, k, n, 0);
        return ans;
    }
};
