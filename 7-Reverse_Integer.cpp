class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN || x == 0) return 0;
        int tmp;
        if(x<0) tmp = 0;
        else tmp = 1;
        int ans = 0;
        x=abs(x);
        while(x){
            if (ans > INT_MAX / 10) // overflow
            {
                return 0;
            }
            ans = ans*10 + x%10;
            x/=10;
        }
        if(tmp) return ans;
        else return 0-ans;
    }
};
