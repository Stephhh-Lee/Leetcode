//这里把输入换为long，才过了。本来是int，一直超时。

class Solution {
public:
    bool isSquare(long i){
        if((int(sqrt(double(i))))*(int(sqrt(double(i)))) == i) return true;
        else return false;
    }
    bool judgeSquareSum(long c) {
        if(c == 0 || isSquare(c)) return true;
        for(long i=1; i*i*2<=c; i++)
            if(isSquare(c-i*i)) return true;
        return false;
    }
};
