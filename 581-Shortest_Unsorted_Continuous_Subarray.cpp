class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        int max_n = nums[0];
        int min_n = nums[len-1];
        int beg = -1;
        int end = -2;
        for(int i = 1; i < len; i++){
            max_n = max(max_n, nums[i]);
            min_n = min(min_n, nums[len-i-1]);
            if(max_n > nums[i]) end = i;
            if(min_n < nums[len-i-1]) beg = len - i -1;
        }
        return end-beg+1;
    }
};