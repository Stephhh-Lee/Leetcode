class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int i,j,first=-1,count=0;
        string ans="";
        for(i=0;i<S.size();i++)
            if(S[i]!='-'){
                first=i;
                break;
            }
        for(i=S.size()-1;i>=0;i--){
            if(S[i]!='-'){
                if(S[i]>='a'&&S[i]<='z') S[i]+='A'-'a';
                ans+=S[i];
                count++;
                if(i!=first && count%K==0) ans+='-';
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
