/*
说明：
1、给定两个vector，vector第一个元素和第二个元素表示矩形的左下角横坐标和纵坐标，
第三个元素和第四个元素表示矩形的右上角横坐标和纵坐标，要求判断这两个矩形是否有
共同区域，也就是是否有交集。

2、笔者总是觉得这道题应该有快速的方法判断，而不应该搞一大堆条件判断。

我们先来想一下一维的情况，如何判断两条线段是否重叠，给定两条线段的起始点
（left1，right1）和结束点（left2，right2）。

如果两条线段重叠，那么必然有某个x满足max(left1,left2)<x<min(right1,righ2)。

所以推广到二维情况：
在横坐标方向上，应该有：
max(rec1[0],rec2[0])<min(rec1[2],rec2[2])，
在纵坐标方向上，应该有：
max(rec1[1],rec2[1])<min(rec1[3],rec2[3])
*/
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return max(rec1[0],rec2[0])<min(rec1[2],rec2[2])&&max(rec1[1],rec2[1])<min(rec1[3],rec2[3]);
    }
};
