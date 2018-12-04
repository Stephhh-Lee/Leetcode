class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        if(num == 0) return {0};
        if(num == 1) return {0,1};
        ans.push_back(0);
        ans.push_back(1);
        for(int i = 2; i <= num; i++){
            if(i%2 == 0) ans.push_back(ans[i/2]);
            else ans.push_back(ans[i-1]+1);
        }
        return ans;
    }
};
