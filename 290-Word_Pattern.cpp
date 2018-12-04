//²»¶Ô

class Solution {
public:
    bool comp(string a, string b){
        if(a.size() != b.size()) return false;
        for(int i=0; i<a.size(); i++){
            if(a[i] != b[i]) return false;
        }
        return true;
    }
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> m;
        vector<string> v;
        for(int i = 0; i < str.size(); i++){
            string s = "";
            while(str[i] != ' '){
                s+=str[i];
                i++;
            }
            if(s.size() != 0) v.push_back(s);
        }
        if(v.size() != pattern.size()) return false;
        for(int i = 0; i < v.size(); i++){
            if(m.find(pattern[i]) == m.end()) m[pattern[i]] = v[i];
            else if(m[pattern[i]] == v[i]) continue;
            else return false;
        }
        return true;
    }
};