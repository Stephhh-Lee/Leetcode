class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        vector<int> robmost(nums.size(), 0);
        robmost[0] = nums[0];
        robmost[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++){
            robmost[i] = max(robmost[i-2] + nums[i], robmost[i-1]);
        }
        return robmost[nums.size()-1];
    }
};
