class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int len = A.size();
        int ans = 0;
        for(int i = 0; i < len; i++){
            int l = 0;
            while(i+l+2<len &&A[i+1]-A[i] == A[i+l+2]-A[i+l+1]) l++;
            ans+=l;
        }
        return ans;
    }
};
