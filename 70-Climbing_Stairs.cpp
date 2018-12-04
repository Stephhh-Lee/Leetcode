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

//�ݹ鳬ʱ��
/*
˼·��
n<=1����ʱֻ��һ�֡�

n>1ʱ������ÿһ��̨��i��Ҫ����̨�ף����һ���������ַ�������i-1��һ�������i-2��������

Ҳ����˵����̨��i�ķ�����=��̨��i-1�ķ�����+��̨��i-2�ķ����������Ը������Ǹ�DP���⡣
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
