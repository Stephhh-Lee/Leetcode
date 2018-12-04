class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        diff &= -diff;
        vector<int> ans(2, 0);
        for(auto a:nums){
            if(a & diff) ans[0] ^= a;
            else ans[1] ^= a;
        }
        return ans;
    }
};
