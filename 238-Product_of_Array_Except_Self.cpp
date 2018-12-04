class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int all = 1;
        int zerocounter = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] != 0)
                all*=nums[i];
            else zerocounter++;
        }
        vector<int> ans(nums.size(), 0);
        if(zerocounter>1) return ans;
        else if(zerocounter == 1){
            for(int i =0; i < nums.size(); i++){
                if(nums[i]==0) ans[i] = all;
            }
            return ans;
        }
        for(int i =0; i < nums.size(); i++){
            ans[i] = all/nums[i];
        }
        return ans;
    }
};



class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int left=1, right=1;
        vector<int> result(n, 1);
        for(int i=0; i<n; i++){
            result[i]*=left;
            result[n-1-i]*=right;
            left*=nums[i];
            right*=nums[n-1-i];
        }
        return result;
    }
};
