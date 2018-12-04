/*
之前有道题Partition Equal Subset Sum有点像，那道题问我们能不能将一个数组
分成和相等的两个子数组，而这道题实际上是让我们将一个数组分成四个和相等的
子数组。我一开始尝试着用那题的解法来做，首先来判断数组之和是否是4的倍数，
然后还是找能否分成和相等的两个子数组，但是在遍历的时候加上判断如果数组中
某一个数字大于一条边的长度时返回false。最后我们同时检查dp数组中一条边长度
位置上的值跟两倍多一条边长度位置上的值是否为true，这种方法不幸TLE了。所以
只能上论坛求助各路大神了，发现了可以用优化过的递归来解，递归的方法基本上等
于brute force，但是C++版本的直接递归没法通过OJ，而是要先给数组从大到小的顺
序排序，这样大的数字先加，如果超过target了，就直接跳过了后面的再次调用递归
的操作，效率会提高不少，所以会通过OJ。下面来看代码，我们建立一个长度为4的
数组sums来保存每个边的长度和，我们希望每条边都等于target，数组总和的四分之
一。然后我们遍历sums中的每条边，我们判断如果加上数组中的当前数字大于target，
那么我们跳过，如果没有，我们就加上这个数字，然后对数组中下一个位置调用递归，
如果返回为真，我们返回true，否则我们再从sums中对应位置将这个数字减去继续循
环
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
其实这题还有迭代的方法，很巧妙的利用到了位操作的特性，前面的基本求和跟判
断还是一样，然后建立一个变量all，初始化为(1 << n) - 1，这是什么意思呢，
all其实是一个mask，数组中有多少个数字，all就有多少个1，表示全选所有的数字，
然后变量target表示一条边的长度。我们建立两个一位向量masks和validHalf，其中
masks保存和target相等的几个数字位置的mask，validHalf保存某个mask是否是总和
的一半。然后我们从0遍历到all，实际上就是遍历所有子数组，然后我们根据mask来
计算出子数组的和，注意这里用了15，而不是32，因为题目中说了数组元素个数不会
超过15个。我们算出的子数组之和如果等于一条边的长度target，我们遍历masks数
组中其他等于target的子数组，如果两个mask相与不为0，说明有公用的数字，直接
跳过；否则将两个mask或起来，说明我们当前选的数字之和为数组总和的一半，更
新validHalf的对应位置，然后我们通过all取出所有剩下的数组，并在validHalf里
查找，如果也为true，说明我们成功的找到了四条边，
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

