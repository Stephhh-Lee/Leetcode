class Solution {
public:
    bool isVowel(char c){
    if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U' \
       ||c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        return true;
    else return false;
    }
    string getA(int num){
        string s = "";
        while(num--){
            s+='a';
        }
        return s;
    }
    string toGoatLatin(string S) {
        string ans;
        int counter = 1;
        for(int i = 0; i < S.size(); i++){
            if(i != 0) ans += " ";
            string str = "";
            while(S[i] != ' ' && i < S.size()){
                str += S[i];
                i++;
            }
            if(!isVowel(str[0])){
                ans += str.substr(1, str.size())+str[0]+"ma"+getA(counter);
            }
            else{
                ans += str+"ma"+getA(counter);
            }
            counter++;
        }
        return ans;
    }
};
