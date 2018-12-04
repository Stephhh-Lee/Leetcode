class Solution {
public:
    void helper(int& loc, bool& tmp, vector<int> vec){
        for(int i=0; i<vec.size(); i++){
            if(vec[i]>loc){
                loc=vec[i];
                tmp=true;
                break;
            }
        }
    }
    bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int>> map;
        for(int i=0; i<t.size(); i++){
            map[t[i]].push_back(i);
        }
        //for(auto x:map){
        //    sort(x.second.begin(), x.second.end());
        //}
        bool tmp;
        int loc=-1;
        for(int i=0; i<s.size(); i++){
            tmp=false;
            helper(loc,tmp,map[s[i]]);
            if(!tmp) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        while(i<s.size()){
            while(j<t.size() && s[i]!=t[j]) j++;
            if(j>=t.size()) return false;
            i++;
            j++;
        }
        return true;
    }
};
