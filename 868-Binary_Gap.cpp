class Solution {
public:
    int binaryGap(int N) {
        int ans = 0;
        int curr = 0, prev = INT_MAX;
        while(N){
            if(N & 1){
                ans = max(ans, curr - prev);
                prev = curr;
            }
            N = N>>1;
            curr++;
        }
        return ans;
    }
};
