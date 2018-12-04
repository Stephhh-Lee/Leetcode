class Solution {
public:
    class comparator {
        public:
        bool operator()(const pair<char, int> &a, const pair<char, int> &b) {
            return (a.second > b.second);
        }
    };
    /*
    int cmp(const pair<char, int> x, const pair<char, int> y)
    {
        return x.second > y.second;
    }
    */
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for(int i = 0; i < s.size(); i++){
            m[s[i]]++;
        }
        string ans = "";
        vector<pair<char, int>> v;
        for(auto x:m){
            v.push_back(make_pair(x.first, x.second));
        }
        sort(v.begin(), v.end(), comparator());
        for(auto x:v){
            for(int i=0;i<x.second;i++)
                ans += x.first;
        }
        return ans;
    }
};


//O(n),no sort, beats 97.83%;
//是又用了一个map，将最大的字符个数mx存起来，然后用find去找mx, mx-1, mx-2, ... ,
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> fc;

        for(auto c: s)
            ++fc[c];

        unordered_map<int, vector<char>> rev;
        int mx = 0;
        for(auto p: fc) {
            rev[p.second].push_back(p.first);
            mx = max(mx, p.second);
        }


        string out;
        for(int i = mx; i; --i) {
            if(rev.find(i) != rev.end())
                for(auto c: rev[i])
                    out += string(i, c);

        }

        return out;

    }
};
