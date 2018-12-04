class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char, char> m;
        unordered_map<char, char> mb;
        vector<string> ans;
        for(auto s:words){
            m.clear();
            mb.clear();
            bool tmp =false;
            if(pattern.size() != s.size()) continue;
            for(int i = 0; i < s.size(); i++){
                //if(m.find(s[i]) == m.end()) m[s[i]] = pattern[i];
                //else if(m[s[i]] != pattern[i]) break;
                if(m.find(pattern[i]) == m.end()){
                    if(mb.find(s[i]) == m.end()){
                        m[pattern[i]] = s[i];
                        mb[s[i]] = s[i];
                    }
                    else break;
                }
                else if(m[pattern[i]] != s[i]) break;
                if(i == s.size() - 1) tmp = true;
            }
            if(tmp) ans.push_back(s);
        }
        return ans;
    }
};
