class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size();
        long int result = 0;
        for(int i = 0; i < len; i++){
            int l=1;
            while(i-l>=0 && i+l<len && s[i-l]==s[i+l]) l++;
            result += l;
            if(i>0 && s[i-1] == s[i]){
                int l = 1;
                while(i-l-1>=0 && i+l<len && s[i-l-1]==s[i+l]) l++;
                result += l;
            }
        }
        return result;
    }
};
