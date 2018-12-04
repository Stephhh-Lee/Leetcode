class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        for(auto x:answers){
            mp[x]++;
        }
        int ans=0;
        for(auto a:mp){
            ans += (a.second + a.first) / (a.first + 1) * (a.first + 1);
        }
        return ans;
    }
};
