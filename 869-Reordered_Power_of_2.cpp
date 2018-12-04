class Solution {
public:
    bool reorderedPowerOf2(int N) {
        int c=counter(N);
        for(int i=0; i<32; i++){
            if(counter(1<<i)==c) return true;
        }
        return false;
    }
    int counter(int n){
        int ret=0;
        for(;n;n/=10){
            ret+=pow(10, n%10);
        }
        return ret;
    }
};
