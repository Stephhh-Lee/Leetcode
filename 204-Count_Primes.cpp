//厄拉多塞筛法
/*
具体操作：先将 2~n 的各个数放入表中，然后在2的上面画一个圆圈，然后划去2的
其他倍数；第一个既未画圈又没有被划去的数是3，将它画圈，再划去3的其他倍数；
现在既未画圈又没有被划去的第一个数 是5，将它画圈，并划去5的其他倍数……依次
类推，一直到所有小于或等于 n 的各数都画了圈或划去为止。这时，表中画了圈的
以及未划去的那些数正好就是小于 n 的素数。
*/


class Solution {
public:
    int countPrimes(int n) {
        bool* del = new bool[n];
        del[2] = false;
        for(int i = 3; i < n; i++) {
            if(i%2==0) del[i] = true;
            else del[i] = false;
        }
        for(int i = 3; i < n; i+=2){
            if(!del[i]){
                if(i*i > n) break;
                for(int j = 2; j*i < n; j++){
                    del[i*j] = true;
                }
            }
        }
        int ans = 0;
        for(int i = 2; i < n; i++){
            if(!del[i]) ans++;
        }
        return ans;
    }
};
