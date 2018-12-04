class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            int j=i;
            while(nums[j]!=j+1){
                //n = nums[j]-1;
                if(nums[j]==nums[nums[j]-1]) break;
                else swap(nums[j], nums[nums[j]-1]);
                //j = n;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i+1){
                ans.push_back(nums[i]);
                ans.push_back(i+1);
                break;
            }
        }
        return ans;
    }
};
