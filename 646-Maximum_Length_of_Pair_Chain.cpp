class Solution {
public:
    //template <typename T>
    class Comp{
    public:
        bool operator()(const vector<int> &a, const vector<int> &b){
            if(a[0] < b[0]) return true;
            if(a[0] == b[0] && a[1]<b[1]) return true;
        
            return false;
        }
    };
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        if(a[0] < b[0]) return true;
        if(a[0] == b[0] && a[1]<b[1]) return true;
        
        return false;
        //return a[0] < b[0];
    }
    void helper(vector<vector<int>> pairs, int& ans, int len, int curr, int last){
        if(curr==pairs.size()){
            ans=max(ans, len);
            return;
        }
        if(last == -1){
            helper(pairs, ans, len+1, curr+1, curr);
            helper(pairs, ans, len, curr+1, last);
        }
        else{
            if(pairs[curr][0]>pairs[last][1]){
                helper(pairs, ans, len+1, curr+1, curr);
                helper(pairs, ans, len, curr+1, last);
            }
            else{
                helper(pairs, ans, len, curr+1, last);
            }
        }
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int len = pairs.size();
        sort(pairs.begin(), pairs.end(), cmp);
        int ans = 0;
        //vector<vector<int>> ans(len, vector<int>(len, 1));
        helper(pairs, ans, 0, 0, -1);
        return ans;
    }
};

上面的超时了
/******************************************************************************/
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), 
             [](vector<int>& l,vector<int>& r){ return (l[1] < r[1]); });
        
        int cnt = 1;
        int old = 0;
        for (int i = 1; i < pairs.size(); ++i) {
            if (pairs[old][1] < pairs[i][0]) {
                ++cnt;
                old = i;
            }
        }
        
        return cnt;
    }
};



