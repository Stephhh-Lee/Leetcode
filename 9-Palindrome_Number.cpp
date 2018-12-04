class Solution {
public:
    string int2str(int n){
        stringstream ss;
        ss<<n;
        string s;
        ss>>s;
        return s;
    }
    bool isPalindrome(int x) {
        if(x < 0) return false;
        string s = int2str(x);
        for(int i = 0; i < s.size()/2; i++){
            if(s[i] != s[s.size()-1-i]) return false;
        }
        return true;
    }
};
