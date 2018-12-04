/*
֮ǰ�е���Partition Equal Subset Sum�е����ǵ����������ܲ��ܽ�һ������
�ֳɺ���ȵ����������飬�������ʵ�����������ǽ�һ������ֳ��ĸ�����ȵ�
�����顣��һ��ʼ������������Ľⷨ�������������ж�����֮���Ƿ���4�ı�����
Ȼ�������ܷ�ֳɺ���ȵ����������飬�����ڱ�����ʱ������ж����������
ĳһ�����ִ���һ���ߵĳ���ʱ����false���������ͬʱ���dp������һ���߳���
λ���ϵ�ֵ��������һ���߳���λ���ϵ�ֵ�Ƿ�Ϊtrue�����ַ�������TLE�ˡ�����
ֻ������̳������·�����ˣ������˿������Ż����ĵݹ����⣬�ݹ�ķ��������ϵ�
��brute force������C++�汾��ֱ�ӵݹ�û��ͨ��OJ������Ҫ�ȸ�����Ӵ�С��˳
������������������ȼӣ��������target�ˣ���ֱ�������˺�����ٴε��õݹ�
�Ĳ�����Ч�ʻ���߲��٣����Ի�ͨ��OJ�������������룬���ǽ���һ������Ϊ4��
����sums������ÿ���ߵĳ��Ⱥͣ�����ϣ��ÿ���߶�����target�������ܺ͵��ķ�֮
һ��Ȼ�����Ǳ���sums�е�ÿ���ߣ������ж�������������еĵ�ǰ���ִ���target��
��ô�������������û�У����Ǿͼ���������֣�Ȼ�����������һ��λ�õ��õݹ飬
�������Ϊ�棬���Ƿ���true�����������ٴ�sums�ж�Ӧλ�ý�������ּ�ȥ����ѭ
��
*/
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(),0);
        if(sum%4!=0 || nums.size() < 4) return false;
        int len = sum/4;
        vector<int> sums(4, 0);
        sort(nums.rbegin(), nums.rend());
        return helper(nums, sums, 0, sum/4);
    }
    bool helper(vector<int>& nums, vector<int>& sums, int pos, int target){
        if(pos == nums.size() - 1){
            return sums[0] == target && sums[1] == target && sums[2] == target;
        }
        for(int i = 0; i < 4; i++){
            if(sums[i] + nums[pos] > target) continue;
            sums[i] += nums[pos];
            if(helper(nums,sums,pos+1,target)) return true;
            sums[i] -= nums[pos];
        }
        return false;
    }
};


/*
��ʵ���⻹�е����ķ���������������õ���λ���������ԣ�ǰ��Ļ�����͸���
�ϻ���һ����Ȼ����һ������all����ʼ��Ϊ(1 << n) - 1������ʲô��˼�أ�
all��ʵ��һ��mask���������ж��ٸ����֣�all���ж��ٸ�1����ʾȫѡ���е����֣�
Ȼ�����target��ʾһ���ߵĳ��ȡ����ǽ�������һλ����masks��validHalf������
masks�����target��ȵļ�������λ�õ�mask��validHalf����ĳ��mask�Ƿ����ܺ�
��һ�롣Ȼ�����Ǵ�0������all��ʵ���Ͼ��Ǳ������������飬Ȼ�����Ǹ���mask��
�����������ĺͣ�ע����������15��������32����Ϊ��Ŀ��˵������Ԫ�ظ�������
����15�������������������֮���������һ���ߵĳ���target�����Ǳ���masks��
������������target�������飬�������mask���벻Ϊ0��˵���й��õ����֣�ֱ��
��������������mask��������˵�����ǵ�ǰѡ������֮��Ϊ�����ܺ͵�һ�룬��
��validHalf�Ķ�Ӧλ�ã�Ȼ������ͨ��allȡ������ʣ�µ����飬����validHalf��
���ң����ҲΪtrue��˵�����ǳɹ����ҵ��������ߣ�
*/
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.empty() || nums.size() < 4) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4 != 0) return false;
        int n = nums.size(), all = (1 << n) - 1, target = sum / 4;
        vector<int> masks, validHalf(1 << n, false);
        for (int i = 0; i <= all; ++i) {
            int curSum = 0;
            for (int j = 0; j <= 15; ++j) {
                if ((i >> j) & 1) curSum += nums[j];
            }
            if (curSum == target) {
                for (int mask : masks) {
                    if ((mask & i) != 0) continue;
                    int half = mask | i;
                    validHalf[half] = true;
                    if (validHalf[all ^ half]) return true;
                }
                masks.push_back(i);
            }
        }
        return false;
    }
};

