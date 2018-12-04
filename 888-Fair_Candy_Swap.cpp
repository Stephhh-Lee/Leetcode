class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int asum = accumulate(A.begin(), A.end(), 0);
        int bsum = accumulate(B.begin(), B.end(), 0);
        int sub = (asum-bsum) / 2;
        unordered_map<int, int> m;
        vector<int> ans;
        for(auto x:B){
            m[x]++;
        }
        for(auto x:A){
            if(m[x-sub]){
                ans.push_back(x);
                ans.push_back(x-sub);
                break;
            }
        }
        return ans;
    }
};
