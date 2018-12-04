//DP:建立一个dp数组

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dpt(amount+1, 0);
        dpt[0] = 1;
        for(auto x:coins)
            for(int i=x;i<=amount;i++){
                dpt[i]+=dpt[i-x];
            }
        return dpt[amount];
    }
};
