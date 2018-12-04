class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask=0, ans=0;
        set<int> prefixSet;
        for(int bit=31; bit>-1; bit--){
            mask |= 1<<bit;
            for(int num : nums){
                prefixSet.insert(num&mask);
            }
            int guess = ans | 1 << bit;
            for(int prefix : prefixSet){
                if(prefixSet.find(prefix^guess)!=prefixSet.end()){
                    ans=guess;
                    break;
                }
            }
            prefixSet.clear();
        }
        return ans;
    }
};
