class Solution {
public:
    bool isWord(char a){
        if((a>='A'&&a<='Z')||(a>='a'&&a<='z'))
            return true;
        return false;
    }
    char toLower(char a){
        if(a>='A'&&a<='Z') a+=32;
        return a;
    }
    void countCharacter(string& s, unordered_map<char, int>& m){
        for(auto x:s){
            if(isWord(x)){
                m[toLower(x)]++;
            }
        }
    }
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int> ml;
        unordered_map<char, int> mw;
        string ans="";
        countCharacter(licensePlate, ml);
        for(auto word:words){
            if(ans.size()==0 || word.size()<ans.size()){
                countCharacter(word, mw);
                bool tmp = true;
                for(auto x:ml){
                    if(!(mw.find(x.first)!=mw.end() && mw[x.first]>=x.second)){
                        tmp = false;
                        break;
                    }
                }
                if(tmp) ans=word;

                mw.clear();
            }
        }
        return ans;
    }
};

class Solution {
private:
    string extractStr(const string &ori) {
        string res("");
        for (auto c : ori) {
            if (c >= 'A' && c <= 'Z') c += 'a'-'A';
            if (c >= 'a' && c <= 'z') res += c;
        }
        sort(res.begin(), res.end());
        return res;
    }

    bool check(const string &pattern, string word) {
        sort(word.begin(), word.end());
        int i = 0, j = 0;
        while (i < pattern.length() && j < word.length()) {
            if (pattern[i] == word[j]) { i++; j++; }
            else { j++; }
        }
        return i == pattern.length();
    }
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        string pattern = extractStr(licensePlate);
        string ans("");
        for (string word : words) {
            if (check(pattern, word)) {
                ans = ans.empty() ? word : word.length() < ans.length() ? word : ans;
            }
        }
        return ans;
    }
};
