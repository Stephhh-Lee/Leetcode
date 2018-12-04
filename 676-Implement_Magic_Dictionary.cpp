class MagicDictionary {
public:
    unordered_map<int, vector<string>> mp;
    /** Initialize your data structure here. */
    MagicDictionary() {

    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto x:dict){
            mp[x.size()].push_back(x);
        }
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        if(mp.find(word.size())==mp.end()) return false;
        for(auto x:mp[word.size()]){
            int similar=0;
            for(int i=0;i<word.size();i++){
                if(x[i]==word[i])similar++;
            }
            if(similar==word.size()-1)return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
