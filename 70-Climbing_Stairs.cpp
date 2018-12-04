class Solution {
public:
    void getStep(int target, int& ans){
        if(target < 0) return;
        if(target == 0) {ans++; return;}
        getStep(target-1, ans);
        if(target>=2)
            getStep(target-2, ans);
    }
    int climbStairs(int n) {
        int ans=0;
        getStep(n, ans);
        return ans;
    }
};

//递归超时了
/*
思路：
n<=1，此时只有一种。

n>1时，对于每一个台阶i，要到达台阶，最后一步都有两种方法，从i-1迈一步，或从i-2迈两步。

也就是说到达台阶i的方法数=达台阶i-1的方法数+达台阶i-2的方法数。所以该问题是个DP问题。
*/
class Solution {
public:
    int climbStairs(int n) {
        vector<int> ans(n+1, 0);
        ans[0] = 0;
        ans[1] = 1;
        ans[2] = 2;
        for(int i =3; i < n+1; i++){
            ans[i] = ans[i-1] +ans[i-2];
        }
        return ans[n];
    }
};
