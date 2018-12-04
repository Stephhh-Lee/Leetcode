/*
[解决思路]
    动态规划解决。
    子问题空间：total_cost记录到达第i个台阶的totalcost（前i个台阶的总cost）；
    关联问题变量与子问题：只有两种状态，从（i-1）走一阶到达i，花费为total_cost[i-1]+cost[i-1]；或从（i-2）走两阶到达i，花费为total_cost[i-2]+cost[i-2]。
    自底向上计算：只有一个台阶和没有台阶时总花费为0.
[时间复杂度]
    遍历一次，耗费时间O(n).

*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int cost_i_1=0,cost_i_2=0;

        int n=cost.size();
        int total_cost=0;

        if(n==1||n==0)
        {
            return 0;
        }

        for(int i=2;i<=n;i++)
        {
            total_cost=min(cost[i-1]+cost_i_1,cost[i-2]+cost_i_2);
            cost_i_2=cost_i_1;
            cost_i_1=total_cost;
        }
        return total_cost;
    }
};
