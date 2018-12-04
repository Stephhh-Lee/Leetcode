class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) return false;
        if(n == 1) return true;
        while(n){
            if(n%2 != 0) return false;
            if(n/2 == 1) return true;
            n/=2;
        }
    }
};

/*
Based on the fact that a power of two and the number before it should be respecitvely:
10000...0
01111...1 // prepended 0 just so that the values line up
Therefore the bitwise AND operator should return 0, as there are no two 1's in the same place.
Values 0 and lower should just be false anyway
*/

bool isPowerOfTwo(int n) {
    return (n > 0) && (n & (n - 1)) == 0;
}
