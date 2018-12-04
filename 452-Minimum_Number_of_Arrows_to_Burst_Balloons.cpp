/*
这道题给了我们一堆大小不等的气球，用区间范围来表示气球的大小，可能会有重叠区间。然后我们用最少的箭数来将所有的气球打爆。那么这道题是典型的用贪婪
算法来做的题，因为局部最优解就等于全局最优解，我们首先给区间排序，我们不用特意去写排序比较函数，因为默认的对于pair的排序，就是按第一个数字升序排
列，如果第一个数字相同，那么按第二个数字升序排列，这个就是我们需要的顺序，所以直接用即可。然后我们将res初始化为1，因为气球数量不为0，所以怎么也得
先来一发啊，然后这一箭能覆盖的最远位置就是第一个气球的结束点，用变量end来表示。然后我们开始遍历剩下的气球，如果当前气球的开始点小于等于end，说明
跟之前的气球有重合，之前那一箭也可以照顾到当前的气球，此时我们要更新end的位置，end更新为两个气球结束点之间较小的那个，这也是当前气球和之前气球的
重合点，然后继续看后面的气球；如果某个气球的起始点大于end了，说明前面的箭无法覆盖到当前的气球，那么就得再来一发，既然又来了一发，那么我们此时就要
把end设为当前气球的结束点了，这样贪婪算法遍历结束后就能得到最少的箭数了，
*/


//先将pair进行一个排序0.0

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if(points.empty()) return 0;
        sort(points.begin(), points.end());
        int ans = 1;
        int end = points[0].second;
        for(int i = 1; i < points.size(); i++){
            if(points[i].first <= end){
                end = min(end, points[i].second);
            }else{
                ans++;
                end = points[i].second;
            }
        }
        return ans;
    }
};
