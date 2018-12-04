class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, pair<int, int>> m;
        for(int i = 0; i < S.size(); i++){
            if(m.find(S[i]) == m.end()) m[S[i]] = make_pair(i,i);
            else m[S[i]].second = i;
        }
        vector<pair<int, int>> vp;
        for(auto x:m){
            vp.push_back(x.second);
        }
        sort(vp.begin(), vp.end());
        vector<int> ans;

        for(auto x:vp){
            if(ans.size() == 0) ans.push_back(x.second);
            else if(x.first < ans[ans.size()-1] && x.second > ans[ans.size()-1]) ans[ans.size()-1] = x.second;
            else if(x.first > ans[ans.size()-1]) ans.push_back(x.second);
        }

        for(int i = ans.size()-1; i >= 0; i--){
            if(i == 0) ans[i]++;
            else{
                ans[i] = ans[i] - ans[i-1];
            }
        }
        return ans;
    }
};
