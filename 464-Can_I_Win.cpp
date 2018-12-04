/*
if(maxn >= desiredTotal) return true;
2.如果所有能够选的数字的总和都小于desiredTotal，再怎么选两个人都不可能赢，
所以肯定输～：
总和就是首项加末项的和乘以项数除以2～：
if((1 + maxn) * maxn / 2 < desiredTotal) return false;
然后建立一个canWin函数，需要用visited标记某个数字是否被选过～因为可选的数字
最大不超过20，则可以用一个整型数组标记，因为整型有32位～如果1被选过就把第1
位（不是第0位哦～当然也可以从0开始啦～）标记为1，如果2被选过就把第2位标记为
1～这样保证所有数字不重复～
所以传入两个值，一个是想要达到（或者说超过，也就是大于等于啦）的目标数字
target，另一个是visited数字标记哪些数字被选过了～
用map标记当前情况在map表中是否存在，存在的话结果保存在map里面～如果我们发现
这个visited也就是这个数字选择的情况已经被保存过了，就直接返回在map里面保存的
结果～
遍历i从1到maxn（maxn是可以选择的最大值，即maxChoosableInteger），表示考虑选
择i的情况，用mask = 1 << i，如果mask和visited进行与运算，如果等于0说明当前的
visited没有被访问过，就可以考虑这个i的情况，如果要选的这个i大于target，不傻
的这个人就会选择i因为肯定能赢啦～还有种情况自己能赢，就是对方输了，即：
canWin(target - i, mask | visited) == false，
（mask | visited表示把i那位也标记为1～）这个时候把visited情况存起来并且
return true，表示赢了～
如果所有数字都遍历完还是没有return true，那就最后return false～return false
之前不要忘记把当前状态存储起来～也就是m[visited] = false; ～
注意：调了两个小时的bug后来才发现！(mask & visited) == 0一开始忘记加括号了，
写成了mask & visited == 0，但是&运算符比==优先级低，所以==会先运算。。所以就
gg了～注意注意～号外号外～
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
