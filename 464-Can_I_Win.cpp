/*
if(maxn >= desiredTotal) return true;
2.��������ܹ�ѡ�����ֵ��ܺͶ�С��desiredTotal������ôѡ�����˶�������Ӯ��
���Կ϶��䡫��
�ܺ;��������ĩ��ĺͳ�����������2����
if((1 + maxn) * maxn / 2 < desiredTotal) return false;
Ȼ����һ��canWin��������Ҫ��visited���ĳ�������Ƿ�ѡ������Ϊ��ѡ������
��󲻳���20���������һ�����������ǣ���Ϊ������32λ�����1��ѡ���Ͱѵ�1
λ�����ǵ�0λŶ����ȻҲ���Դ�0��ʼ���������Ϊ1�����2��ѡ���Ͱѵ�2λ���Ϊ
1��������֤�������ֲ��ظ���
���Դ�������ֵ��һ������Ҫ�ﵽ������˵������Ҳ���Ǵ��ڵ���������Ŀ������
target����һ����visited���ֱ����Щ���ֱ�ѡ���ˡ�
��map��ǵ�ǰ�����map�����Ƿ���ڣ����ڵĻ����������map���桫������Ƿ���
���visitedҲ�����������ѡ�������Ѿ���������ˣ���ֱ�ӷ�����map���汣���
�����
����i��1��maxn��maxn�ǿ���ѡ������ֵ����maxChoosableInteger������ʾ����ѡ
��i���������mask = 1 << i�����mask��visited���������㣬�������0˵����ǰ��
visitedû�б����ʹ����Ϳ��Կ������i����������Ҫѡ�����i����target����ɵ
������˾ͻ�ѡ��i��Ϊ�϶���Ӯ��������������Լ���Ӯ�����ǶԷ����ˣ�����
canWin(target - i, mask | visited) == false��
��mask | visited��ʾ��i��λҲ���Ϊ1�������ʱ���visited�������������
return true����ʾӮ�ˡ�
����������ֶ������껹��û��return true���Ǿ����return false��return false
֮ǰ��Ҫ���ǰѵ�ǰ״̬�洢������Ҳ����m[visited] = false; ��
ע�⣺��������Сʱ��bug�����ŷ��֣�(mask & visited) == 0һ��ʼ���Ǽ������ˣ�
д����mask & visited == 0������&�������==���ȼ��ͣ�����==�������㡣�����Ծ�
gg�ˡ�ע��ע�⡫������⡫
*/
class Solution {
private:
    int maxn;
    map<int, bool> m;
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        maxn = maxChoosableInteger;
        if(maxChoosableInteger >= desiredTotal) return true;
        if((1+maxChoosableInteger)*maxChoosableInteger/2 < desiredTotal) return false;
        return helper(desiredTotal, 0);
    }
    bool helper(int target, int visited){
        if(m.find(visited) != m.end()) return m[visited];
        for(int i= 1; i <= maxn; i++){
            int mask = (1<<i);
            if((mask & visited) == 0 && (i >= target || helper(target - i, mask | visited) == false)){
                m[visited] = true;
                return true;
            }
        }
        m[visited] = false;
        return false;
    }
};
