class Solution {
public:
    string helper(int n){
        string s;
        if(n%16>=10) s = 'a'+n%10;
        else s = '0'+n%16;
        return s;
    }
    string toHex(int num) {
        if(num == 0) return "0";
        int tag = INT_MIN, sum = 0;
        string ans = "";
        for(int i = 1; i <= 32; i++){
            if(num & tag) sum = sum*2+1;
            else sum *= 2;
            if(i%4 == 0){
                if(ans.size()!=0 || sum != 0)
                    ans += helper(sum);
                sum = 0;
            }
            num = num<<1;
        }
        /*
        for(int i = 1; i <= 32; i++){
            if(num & tag) ans += "1";
            else ans += "0";
            num<<=1;
        }
        */
        return  ans;
    }
};
