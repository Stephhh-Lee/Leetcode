class Solution {
public:
    void helper(vector<vector<int>>& ans, unordered_map<int, bool>& mp, vector<int> v, int n){
        if(n==0) {
            ans.push_back(v);
            return;
        }
        for(auto it=mp.begin(); it!=mp.end(); it++){
            if(it->second==false){
                mp[it->first]=true;
                n--;
                v.push_back(it->first);
                helper(ans, mp, v, n);
                mp[it->first]=false;
                n++;
                v.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> vec;
        unordered_map<int, bool> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]=false;
        }
        helper(ans, mp, vec, nums.size());
        return ans;
    }
};
