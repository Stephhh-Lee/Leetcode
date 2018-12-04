class Solution {
public:
    string customSortString(string s, string t) {
        unordered_map<char, int> m, mm;
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            m[s[i]] = 1;
        }
        for(int i = 0; i < t.size(); i++){
            if(m.find(t[i]) == m.end())
                m[t[i]] = 2;
            mm[t[i]] ++;
        }
        for(auto x:m){
            if(x.second == 2)
                while(mm[x.first]--)
                    ans+=x.first;
        }
        for(int i = 0; i < s.size(); i++){
            if(mm.find(s[i]) != mm.end())
                while(mm[s[i]]--)
                    ans+=s[i];
        }
        //ans+=s;
        return ans;
    }
};