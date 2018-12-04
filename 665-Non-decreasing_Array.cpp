class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool tmp = true;
        if(nums.size() < 3) return true;
        int prev = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i]>=nums[i-1]){
                continue;
            }
            if(tmp){
                if(i-2<0) nums[i]=nums[i-1]=min(nums[i], nums[i-1]);
                else if(nums[i]>=nums[i-2]) nums[i-1] = nums[i];
                else nums[i] = nums[i-1];
                tmp = false;
            }
            else return false;
        }
        return true;
    }
};
