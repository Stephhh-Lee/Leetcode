class Solution {
public:
    bool isFront(char c){
        if(c == '[' || c == '{' || c == '(') return true;
        else return false;
    }
    bool isPair(char a, char b){
        if((a == '[' && b == ']') || (a == '{' && b == '}') ||(a == '(' && b == ')')) return true;
        else return false;
    }
    bool isValid(string s) {
        stack<char> ss;
        if(s.size()%2 != 0) return false;
        for(int i = 0; i < s.size(); i++){
            if(ss.empty()) ss.push(s[i]);
            else if(isFront(s[i])) ss.push(s[i]);
            else{
                if(!isPair(ss.top(), s[i])) return false;
                else ss.pop();
            }
        }
        if(ss.empty())
            return true;
        else return false;
    }
};