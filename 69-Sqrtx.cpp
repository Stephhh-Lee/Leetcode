//傻逼玩意，改成long i就过了
//使用二分可以加快速度吧

class Solution {
public:
    int mySqrt(int x) { 
        long i = 1;
        for(; i*i <= x; i++){
        }
        return i-1;
    }
};


/*
另一种解法是 牛顿迭代法，思想参考百度百科 以及参考博客 
为了方便理解，就先以本题为例： 

计算x2 = n的解，令f(x)=x2-n，相当于求解f(x)=0的解，如左图所示。

首先取x0，如果x0不是解，做一个经过(x0,f(x0))这个点的切线，与x轴的交点为x1。

同样的道理，如果x1不是解，做一个经过(x1,f(x1))这个点的切线，与x轴的交点为x2。

以此类推。

以这样的方式得到的xi会无限趋近于f(x)=0的解。

判断xi是否是f(x)=0的解有两种方法：

一是直接计算f(xi)的值判断是否为0，二是判断前后两个解xi和xi-1是否无限接近。

经过(xi, f(xi))这个点的切线方程为f(x) = f(xi) + f’(xi)(x - xi)，其中f’(x)为f(x)的导数，本题中为2x。令切线方程等于0，即可求出xi+1=xi - f(xi) / f’(xi)。

继续化简，xi+1=xi - (xi2 - n) / (2xi) = xi - xi / 2 + n / (2xi) = xi / 2 + n / 2xi = (xi + n/xi) / 2。
*/
class Solution {
public:
    int mySqrt(int x) {
        if (x < 0)
            return -1;

        //使用二分法求解
        unsigned long long lhs = 0, rhs = (x + 1) / 2;

        while (lhs <= rhs)
        {
            unsigned long long mid = (lhs + rhs) / 2;
            //注意溢出问题，使用无符号长整型存储临时乘积
            unsigned long long tmp1 = mid * mid;
            if (tmp1 == x)
            {
                return mid;
            }
            else if (tmp1 < x)
            {
                lhs = mid + 1;
            }               
            else{
                rhs = mid - 1;
            }//else
        }//while

        unsigned long long tmp = lhs * lhs;
        if (tmp <= x)
            return lhs;
        else
            return rhs;
    }
};
