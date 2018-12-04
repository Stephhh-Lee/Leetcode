/*
[���˼·]
    ��̬�滮�����
    ������ռ䣺total_cost��¼�����i��̨�׵�totalcost��ǰi��̨�׵���cost����
    ������������������⣺ֻ������״̬���ӣ�i-1����һ�׵���i������Ϊtotal_cost[i-1]+cost[i-1]����ӣ�i-2�������׵���i������Ϊtotal_cost[i-2]+cost[i-2]��
    �Ե����ϼ��㣺ֻ��һ��̨�׺�û��̨��ʱ�ܻ���Ϊ0.
[ʱ�临�Ӷ�]
    ����һ�Σ��ķ�ʱ��O(n).

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
