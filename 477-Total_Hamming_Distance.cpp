class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<32;i++){
            int mask=1<<i;
            int counter=0;
            for(int num:nums){
                if((num&mask)!=0) counter++;
            }
            ans+=counter*(nums.size()-counter);
        }
        return ans;
    }
};
