class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int ans = 1;
        vector<int> tmp;
        tmp.push_back(nums[0]);
        for(int i =0; i < nums.size() - 1; i++){
            if(nums[i] != nums[i+1]){
                ans++;
                tmp.push_back(nums[i+1]);
            }
        }
        for(int i = 0; i < ans; i++){
            nums[i] = tmp[i];
        }
        return ans;
    }
};
