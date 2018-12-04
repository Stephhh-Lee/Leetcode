//看着挺牛逼的一道题，一下就A了，感觉有点懵逼；

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int nStart = 0, nEnd = 0;
        int sum = 0;
        int ans = INT_MIN;
        int s = 0,e = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum>ans){
                ans=sum;
                nStart = s;
                nEnd = e;
            }
            if(sum < 0){
                s = e = i+1;
                sum = 0;
            }
            e++;
        }
        return ans;
    }
};
