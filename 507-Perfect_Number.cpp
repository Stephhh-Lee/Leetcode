class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 0 || num == 1) return false;
        int sum = 1;
        //if(num%2 == 0) sum += num/2;
        for(int i = 2; i*i<=num; i++){
            if(num%i == 0) sum=sum+i+num/i;
            if(i*i==num) sum-=i;
        }
        if(sum == num) return true;
        else return false;
    }
};
