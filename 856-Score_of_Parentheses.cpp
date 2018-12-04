class Solution {
public:
    int scoreOfParentheses(string S) {
        int ret = 0;
        stack<int> stk;
        for (int i = 0; i < S.length(); i++){
            switch(S[i]){
                case '(':
                    if (S[i + 1] == ')'){
                        ret += 1;
                        i++;
                    }
                    else{
                        stk.push(ret);
                        ret = 0;
                    }
                    break;
                case ')':
                    ret *= 2;
                    ret += stk.top();
                    stk.pop();
                    break;
            }
        }
        return ret;
    }
};
