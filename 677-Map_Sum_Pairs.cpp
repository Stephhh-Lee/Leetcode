class TrieNode {
    public:
    int last;
    TrieNode *children[26];
    TrieNode()
    {
        last = 0;
        for(int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
};
class MapSum {
public:
    TrieNode *root;
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }

    void insert(string key, int val) {
        TrieNode *curr = root;
        for(int i = 0; i < key.size(); i++)
        {
            int index = key[i] - 'a';
            if(!curr->children[index])
                curr->children[index] = new TrieNode;
            curr = curr->children[index];
        }
        curr->last = val;
    }
    void dfs(TrieNode *curr, int &sum)
    {
        if(curr->last != 0)
            sum+= curr->last;
        for(int i = 0; i < 26; i++)
        {
            if(curr->children[i])
                dfs(curr->children[i], sum);
        }
    }
    int sum(string prefix) {
        TrieNode *curr = root;
        int res = 0;
        for(int i = 0; i < prefix.size(); i++)
        {
            int index = prefix[i]-'a';
            if(!curr->children[index])
                return res;
            curr = curr->children[index];
        }
        dfs(curr, res);
        return res;
    }
};
