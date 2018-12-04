class MyHashSet {
public:
    vector<bool> v;
public:
    /** Initialize your data structure here. */
    MyHashSet() {

    }

    void add(int key) {
        if(key >= v.size()){
            for(int i = v.size();i<=key;i++) v.push_back(false);
        }
        v[key] = true;
    }

    void remove(int key) {
        if(key < v.size()) v[key] = false;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        if(key < v.size()) return v[key];
        else return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */
