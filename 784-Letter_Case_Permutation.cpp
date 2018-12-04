class Solution {
public:
    string toLower(string s, int i){
        if(s[i]>='A'&&s[i]<='Z')
            s[i] = s[i] - 'A' + 'a';
        return s;
    }
    string toUpper(string s, int i){
        if(s[i]>='a'&&s[i]<='z')
            s[i] = s[i] - 'a' + 'A';
        return s;
    }
    vector<string> letterCasePermutation(string S) {
        queue<string> q;
        q.push(S);
        for(int i = 0; i < S.size(); i++){
            int size = q.size();
            if((S[i]>='a'&&S[i]<='z')||(S[i]>='A'&&S[i]<='Z')){
                while(size--){
                    string str = q.front();
                    q.pop();
                    q.push(toLower(str, i));
                    q.push(toUpper(str, i));
                }
            }
        }
        vector<string> ans;//(q.begin(), q.end());
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};
