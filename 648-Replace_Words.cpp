class Solution {
public:
    struct TrieNode{
    //int weight;
    TrieNode *children[27];
    bool isExist;
    TrieNode(){
        isExist = false;
        for(int i=0;i<27;i++) children[i]=nullptr;
        };
    };
    void buildDict(vector<string> dict,TrieNode* tn){
        for(auto x:dict){
            TrieNode* node = tn;
            for(auto a:x){
                if(node->children[a-'a']==nullptr){
                    node->children[a-'a'] = new TrieNode();
                }
                node=node->children[a-'a'];
            }
            for(int i=0; i<26; i++){
                node->children[i] = nullptr;
            }
            node->isExist=true;
        }
        return;
    }
    string inDict(string word, TrieNode* tn){
        TrieNode* node=tn;
        string ans="";
        for(auto a:word){
            if(node->isExist==true) return ans;
            else if(node->children[a-'a']==nullptr) return word;
            ans+=a;
            node=node->children[a-'a'];
        }
        return word;
    }
    string replaceWords(vector<string>& dict, string sentence) {
        TrieNode* tn = new TrieNode();
        buildDict(dict, tn);
        string ans="";
        string word="";
        for(int i=0; i<sentence.size(); i++){
            if(sentence[i]==' ' || i==sentence.size()-1){
                if(i==sentence.size()-1) word+=sentence[i];
                ans+=inDict(word,tn);
                word="";
                if(i==sentence.size()-1) break;
                ans+=" ";
            }
            else word+=sentence[i];
        }
        return ans;
    }
};
