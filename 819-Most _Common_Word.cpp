class Solution {
public:
    string toLowercase(string s){
        for(int i = 0; i < s.size(); i++){
            if(s[i]>='A' && s[i]<='Z')
                s[i] = s[i] - 'A' + 'a';
        }
        return s;
    }
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> m;
        unordered_map<string, int> mb;
        for(auto x:banned){
            mb[x]++;
        }
        for(int i = 0; i < paragraph.size(); i++){
            string s = "";
            char c = paragraph[i];
            while(i<paragraph.size() && ((paragraph[i]>='a'&&paragraph[i]<='z') || (paragraph[i]>='A'&&paragraph[i]<='Z'))){
                s += paragraph[i];
                i++;
            }
            if(s.size()>0)
                m[toLowercase(s)]++;
        }
        int max = INT_MIN;
        string ans = "";
        for(auto x:m){
            if(x.second>max && mb[x.first] != 1){
                max = x.second;
                ans = x.first;
            }
        }
        return ans;
    }
};
