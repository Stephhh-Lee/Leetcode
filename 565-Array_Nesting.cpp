class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        vector<int> tag(nums.size(), -1);
        int ans = -1;
        for(int i=0;i<nums.size(); i++){
            int num=0;
            while(tag[i]!=i){
                tag[i]=i;
                i=nums[i];
                num++;
            }
            ans=max(ans, num);
        }
        return ans;

    }
};
