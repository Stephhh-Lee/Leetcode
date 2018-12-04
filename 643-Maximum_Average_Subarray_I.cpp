class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int num = 0;
        //int ans=INT_MAX;
        for(int i = 0; i < k; i++){
            num += nums[i];
        }
        int ans = num;
        for(int i = k; i < nums.size(); i++){
            num += nums[i];
            num -= nums[i-k];
            ans = max(ans, num);
        }
        return double(ans)/k;
    }
};
