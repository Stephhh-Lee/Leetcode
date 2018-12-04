class Solution {
public:
    bool isPerfectSquare(int num) {
        if( num == 1 || num == 0 )
            return true;
        long sqrt = 1;
        long square = sqrt * sqrt;
        while(square != num){
            sqrt++;
            square = sqrt * sqrt;
            if(square > num)
                return false;
        }
        return true;
    }
};
