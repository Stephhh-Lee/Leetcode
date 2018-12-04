class Solution {
public:
    bool backspaceCompare(string S, string T) {

        int sc = 0, tc = 0;
        for(int i=S.size()-1, j=T.size()-1; i>=0 || j>=0;){
            while((sc!=0 && i>=0) || S[i]=='#'){
                if(S[i]!='#') sc--;
                if(S[i]=='#') sc++;
                i--;
            }
            while((tc!=0 && j>=0) || T[j]=='#'){
                if(T[j]!='#') tc--;
                if(T[j]=='#') tc++;
                j--;
            }
            if(i>=0 && j>=0){
                if(S[i]!=T[j]) return false;
                i--;
                j--;
            }else{
                if(i>=0 && S[i]!='#') return false;
                if(j>=0 && T[j]!='#') return false;
            }

        }
        return true;
    }
};
