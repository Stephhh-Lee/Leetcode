class Solution {
public:
    bool isVowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U') return true;
        return false;
    }
    string reverseVowels(string s) {
        vector<int> v;
        for(int i=0; i<s.size(); i++){
            if(isVowel(s[i])) v.push_back(i);
        }
        for(int i=0; i<v.size()/2; i++){
            swap(s[v[i]], s[v[v.size()-1-i]]);
        }
        return s;
    }
};
