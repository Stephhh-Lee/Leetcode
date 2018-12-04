class Solution {
public:
    bool isLetter(char c){
        if((c>='a'&&c<='z') || (c>='A'&&c<='Z') || (c>='0'&&c<='9'))
            return true;
        else return false;
    }
    bool notSame(char a, char b){
        if( a == b) return false;
        //if((a>='0'&&a<='9') && a == b) return true;
        else{
            if(a>='A'&&a<='Z') a+=32;
            if(b>='A'&&b<='Z') b+=32;
            if(a == b) return false;
        }
        return true;
    }

    bool isPalindrome(string s) {
        for(int i = 0, j = s.size()-1; i<j; i++, j--){
            while(!isLetter(s[i])) i++;
            while(!isLetter(s[j])) j--;
            if(i>=j) break;
            if(notSame(s[i], s[j])) return false;
        }
        return true;
    }
};

