class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int tmp = 0;
        for(int i = digits.size()-1; i >= 0; i--)
        {
            if(i == digits.size()-1){
                ans.push_back((digits[i]+1)%10);
                if((digits[i]+1)/10 == 1) tmp = 1;
            }
            else{
                ans.push_back((digits[i]+tmp)%10);
                if((digits[i]+tmp)/10 == 1) tmp = 1;
                else tmp = 0;
            }
        }
        if(tmp) ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
