//这里的save 和 prev 之前没有弄清楚

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1, 0);
        for(int i=0; i < ans.size(); i++){
            ans[i]=1;
            int save, prev = 1;
            for(int j=1;j<i;j++){
                save = ans[j];
                ans[j]+=prev;
                prev = save;
            }
        }
        return ans;
    }
};
