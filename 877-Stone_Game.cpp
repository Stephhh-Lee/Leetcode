/*
解法1： 直接返回true[Accepted]
这个题目有趣的地方在于，通过它给出的限制条件可以直接判断谁能胜利。
Alex是第一个去选择的人，而且piles.length是偶数，这就导致了：Alex可以总是选下标为偶数的piles或者下标为奇数的piles。
举个例子，piles.length=n且为偶数。
如果Alex想去选择下标为偶数的piles，他第一轮可以选择piles[0].之后Lee只能从piles[1]~piles[n-1]中做出选择，而无论哪种选择都可以使得Alex下一轮
继续选择下标为偶数的piles。这样循环往复，Alex可以将所有下标为偶数的piles选走，而Lee只能选择下标为奇数的piles。反之亦然。
同时题目还给出了一个条件，就是sum(piles)是奇数。如果sum(piles[even]) > sum(piles[odds])那么Alex选择偶数的piles即可取得胜利，反之选择奇数的
piles即可取得胜利。
综上，Alex总是可以赢，直接return true即可AC。

*/
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};

/*
解法2： DP
解法1需要很多的限制条件才可以成立，而且这样解题并不是作者本身的意图，对于一般性情况，本题目可以通过动态规划求解。其中一般情况是指：如果
piles.length为奇数该怎么办？或者我们想明确的知道分数的差距又该如何处理？

对于动态规划的题，一般求什么就设什么。在这里我们设dp[i][j]表示从piles[i]到piles[j]你可以比对手多得的最多的分数。这样我们的最终目标是dp[0][n-1]。
现在我们需要确定转移方程和初始条件。
在piles[i]~piles[j]中，你可以选择piles[i]或者piles[j]：
如果你选择了piles[i]，那么你的对手就会从piles[i+1]~piles[j]中得到最多的分数，分数差值为piles[i]-dp[i+1][j].(题目要求都发挥最佳水平，所以对于对
手而言dp的含义一样。,他会从剩下的piles中选择最多的分数，所以两者做减法。）
如果你选择了piles[j],分数差值为piles[j] - dp[i][j-1].

所以状态转移方程为：
dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1])

初始条件为：
当 i == j 时， dp[i][i] = piles[i]
*/
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) dp[i][i] = piles[i];
        for(int len = 2; len <= n; len++){
            for(int i = 0; i <= n - len; i++){
                dp[i][i+len-1] = max(piles[i] - dp[i+1][i+len-1], piles[i+len-1] - dp[i][i+len-2]);
            }
        }
        return dp[0][n-1]>0;
    }
};
