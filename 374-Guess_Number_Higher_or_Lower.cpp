// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int s = 0, e = n, mid;
        while(s <= n){
            mid = s+(e-s)/2;
            if(guess(mid) == 1) s = mid + 1;
            else if(guess(mid) == -1) e = mid - 1;
            else if(guess(mid) == 0) return mid;
        }
    }
};
